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
    def get_bloc_img(self, pos, source):
        num = self.data[self.size[1] * pos[0] + pos[1]]
        print(num)
        im = cv2.imread(source)
        h, w, a = im.shape
        ny = h // 16
        nx = w // 16
        sy = num // nx
        sx = num % nx
        img = Image.open(source)
        imgcrop = img.crop((sx * 16, sy * 16, sx * 16 + 16, sy * 16 + 16))
        imgcrop.show()
          

def get_map():
    map = sys.argv[1]
    j = json.load(open(map, "r"))
    res = Map(j["width"], j["height"], j["tilewidth"], j["tileheight"])
    for l in j["layers"]:
        layer = Layer(l["width"], l["height"], l["name"], l["id"], l["data"])
        res.layers.append(layer)
    for t in j["tilesets"]:
        res.tilesets.append([t["firstgid"], t["source"]])
    return res

    
map = get_map()
map.layers[0].get_bloc_img((0, 0), "Room_Builder_free_16x16.png")

