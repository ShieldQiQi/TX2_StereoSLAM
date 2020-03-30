from PyQt5.QtGui import *
import os
 
img = QImage()
path = "./"
for root , dirs, files in os.walk(path):
    for name in files:
        print(name)
        if name.endswith(".png"):
            print(name)
            img.load("./"+name)
            img.save("./"+name)
