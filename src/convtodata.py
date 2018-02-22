#!/bin/python
from PIL import Image
import os
import sys
if len(sys.argv) <= 1:
    print("Enter output file name and path of directory containing images")
else:
    try:
        opfile=open(sys.argv[1],"wb")
        totalSize=0
        fc=0
        for i in range(2, len(sys.argv)):
            print("Entering %s" % sys.argv[i])
            try:
                for f in os.listdir(sys.argv[i]):
                    try:
                        im = Image.open(sys.argv[i] + "/" + f)
                        ba=bytearray(im.getdata())
                        fc+=1
                        opfile.write(ba)
                        #print(len(ba))
                        totalSize+=len(ba)
                    except Exception as e:
                        print("Exception while opening image %r"%e)
            except Exception as ee:
                print("Exception while opening dir %r"%ee)
        opfile.close()
        print("Output File size: %r Bytes  %r KB  %r MB"%(totalSize,totalSize/1024,totalSize/1048576))
        print("%r files expected o/p size %r Bytes"%(fc,fc*28*28))
    except Exception as e:
        print("Exception while opening file %s %r"%(sys.argv[1],e))