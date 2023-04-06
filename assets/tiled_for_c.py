import sys
import json
from PIL import Image
import cv2
import math

class Map:
    def __init__(self, width, height, twidth, theight):
        self.size = (width, height)
        self.tile_size = (twidth,theight)
        self.layers = list()
        self.tilesets = list()
    def print_data(self):
        print("Map (%dx%d) with tiles (%dx%d)" % (self.size[0], self.size[1], self.tile_size[0], self.tile_size[1]))
        for l in self.layers:
            print("Layer %s (%dx%d) id %d" % (l.name, l.size[0], l.size[1], l.id))
            print(l.data)
class Layer:
    def __init__(self, width, height, name, id, data):
        self.size = (width, height)
        self.name = name
        self.id = id
        self.data = data
    def get_sprite_pos(self, num, source):
        im = cv2.imread(source)
        h, w, a = im.shape
        x = (num - 1) % (w // 16) * 16
        y = math.floor((num - 1) / (w // 16)) * 16
        return (x, y)
    def get_sprite_tileset(self, num, tilesets):
        for i in range(len(tilesets) - 1, -1, -1):
            if num >= tilesets[i][0]:
                return i
    def get_layer_data(self, f, tilesets):
        for sprite in self.data:
            if not sprite:
                f.write("0\n")
                continue
            tileset = self.get_sprite_tileset(sprite, tilesets)
            pos = self.get_sprite_pos(sprite - tilesets[tileset][0] + 1, tilesets[tileset][1])
            f.write(str(tileset) + " " + str(pos[0]) + " " + str(pos[1]) + "\n")

def get_map():
    map = sys.argv[1]
    j = json.load(open(map, "r"))
    res = Map(j["width"], j["height"], j["tilewidth"], j["tileheight"])
    for l in j["layers"]:
        layer = Layer(l["width"], l["height"], l["name"], l["id"], l["data"])
        res.layers.append(layer)
    for t in j["tilesets"]:
        res.tilesets.append([t["firstgid"], t["source"].replace("tsx", "png")])
    return res

    
map = get_map()
f = open("res.map", "w")
f.write("#width\n" + str(map.size[0]) + "\n")
f.write("#height\n" + str(map.size[1]) + "\n")
f.write("#nb_tilesets\n" + str(len(map.tilesets)) + "\n")
f.write("#tilesets\n")
for sheet in map.tilesets:
    f.write(sheet[1] + "\n")
for layer in map.layers:
    f.write("#layer\n")
    layer.get_layer_data(f, map.tilesets)