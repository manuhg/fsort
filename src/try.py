import os,sys
import pandas as pd
import numpy
from sklearn.decomposition import PCA
from PIL import Image


def resize(im):
    #baseval=420
    #maxd=baseval*baseval
    #imwp=float(baseval/float(im.size[0]))
    #imhs=int(float(im.size[1])*imwp)
    #imar=float(im.size[0])/float(im.size[1])
    #ims=float(im.size[0])+float(im.size[1])
    #imw=int((float(im.size[0])/ims)*maxd)
    #imh=int(maxd/int(imw))
    #im.resize((714,420),Image.ANTIALIAS)
    return im

def read_images(dir,rsz=False,ba_lst=[]):
    try:
        totalSize=0
        fc=0
        flst=[]
        print("Entering %s" % dir)
        try:
            for f in os.listdir(dir):
                try:
                    print("\n%r"%f)
                    im = Image.open(dir + "/" + f)
                    if not im:
                        continue
                    #if rsz:
                    #    im.resize((714,420),Image.ANTIALIAS)
                    #    im.save(dir+"/"+f)
                    na=numpy.asarray(im.getdata())
                    ba_lst.append(na)
                    flst.append(f)
                    fc+=1
                    totalSize+=len(na)
                except Exception as e:
                    print("Exception while opening image %r"%e)
        except Exception as ee:
            print("Exception while opening dir %r"%ee)
        print("\nFiles processed: %r\nOutput  size:\n %r Bytes  %r KB  %r MB"%(fc,totalSize,totalSize/1024,totalSize/1048576))
    except Exception as e:
        print("Exception while opening file %s %r"%(dir,e))
    return (flst,ba_lst)

def genhtml(dir,imlst,fname):
    html="<html><head><title>Images list</title></head><body><table><tr><th>image</th></tr>"
    for im in imlst:
        html+="<tr><td><img src=\""+dir+"/"+im+"\"/></td></tr>"
    html+="</table></body></html>"
    f=open(fname,"w")
    f.write(html)
#df['pca-one'] = pca_result[:,0]
#df['pca-two'] = pca_result[:,1]
#df['pca-three'] = pca_result[:,2]

def fsort():
    pca = PCA(n_components=1)
    if len(sys.argv)>1:
        resz=False
        #if len(sys.argv)>2:
         #   if sys.argv[2] is not None:
          #      resz=True
        flst,ba_lst_=read_images(sys.argv[1],resz)
        pca_result = pca.fit_transform(ba_lst_)
        cd={}
        for i in range(len(flst)):
            cd[flst[i]]=ba_lst_[i]
        clst=sorted([(v,k) for k,v in cd.items() ])
        files=[elem[1] for elem in clst]
        genhtml(sys.argv[1],files,"fsort.html")

fsort()
