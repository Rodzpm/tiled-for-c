import sys
import json
import cv2
import math

class Map:
    def __init__(self, width, height, twidth, theight):
        self.size = (width, height)
        self.tile_size = (twidth,theight)
        self.layers = list()
        self.tilesets = list()

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
    def get_layer_data(self, f, tilesets, map):
        for y in range(map.size[1]):
            for x in range(map.size[0]):
                if (self.data[y * map.size[0] + x] != 0):
                    f.write(str(x * 16) + " " + str(y * 16) + "\n")

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
f = open("res.coll", "w")
for layer in map.layers:
    if layer.name == "Collision":
        layer.get_layer_data(f, map.tilesets, map)