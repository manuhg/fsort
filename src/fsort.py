import os,sys
import numpy as np
import tensorflow as tf
from sklearn.manifold import TSNE as tsne
from sklearn.decomposition import PCA
FLAGS = tf.app.flags.FLAGS
tf.app.flags.DEFINE_string(
    'model_dir', '/home/gk1000/imagenet', """Path to classify_image_graph_def.pb, """
    """imagenet_synset_to_human_label_map.txt, and """
    """imagenet_2012_challenge_label_map_proto.pbtxt.""")
tf.app.flags.DEFINE_string('image_file', '', """Absolute path to image file.""")
tf.app.flags.DEFINE_integer('num_top_predictions', 5, """Display this many predictions.""")

def create_graph():
  # Creates graph from saved graph_def.pb.
  with tf.gfile.FastGFile(os.path.join(FLAGS.model_dir, 'classify_image_graph_def.pb'), 'rb') as f:
    graph_def = tf.GraphDef()
    graph_def.ParseFromString(f.read())
    _ = tf.import_graph_def(graph_def, name='')

def get_pool_arr(dir):
  create_graph()
  pool_list=[]
  flst=[]
  with tf.Session() as sess:
    softmax_tensor = sess.graph.get_tensor_by_name('softmax:0')
    print("Dir:"+dir)
    for image in os.listdir(dir):
      s=image.split('.')
      if not s or s[-1] not in ['jpg','jpeg','png']:
            continue
      try:
        print(image)
        if not tf.gfile.Exists(dir+"/"+image):
          tf.logging.fatal('%s does not exist'%image)        
        with tf.gfile.FastGFile(dir+"/"+image, 'rb') as image_file:
          image_data =  image_file.read()
          predictions = sess.run(softmax_tensor, {'DecodeJpeg/contents:0': image_data})
          predictions = np.squeeze(predictions)          
          feature_tensor = sess.graph.get_tensor_by_name('pool_3:0')
          feature_set = sess.run(feature_tensor, {'DecodeJpeg/contents:0': image_data})
          val_lst=sess.run(feature_tensor)[0][0][0]
          pool_list.append(val_lst)
          flst.append(image)
      except Exception as e:
        print("\nException while generating pool list\n%r"%e)            
  return (flst,np.array(pool_list))

def run_tsne(pool_arr):
    #pca_m=PCA(n_components=1024)
    pca_res=pool_arr#pca_m.fit_transform(pool_arr)
    ts_model=tsne(n_components=1,perplexity=25,n_iter=1600,learning_rate=80)
    embeddings=ts_model.fit_transform(pca_res)
    return embeddings
def fsort(dir):
    pool_info=get_pool_arr(dir)
    embeddings=run_tsne(pool_info[1])
    result={}
    for k in range(len(embeddings)):
        result[pool_info[0][k]]=embeddings[k].tolist()[0]
    result=sorted([(v,k) for k,v in result.items() ])
    flist_html='var flist=['
    for (v,fname) in result:
        comma=","
        if fname==result[-1][1]:
            comma=""
        flist_html+="'"+fname+"'"+comma
    flist_html+='];'
    return flist_html

def main(_):
  if len(sys.argv) < 2:
    print("please provide a path to one or more images, e.g. images/* or images/*.jpg etc..")
    sys.exit()
  else:
    for i in range(1,len(sys.argv)):
        flist_html=fsort(sys.argv[i])
        try:
            dname=sys.argv[i].split("/")
            if dname:
                dname=dname[-1]
            #f=open(dname+".js","w")
            f=open("flst.js","w")
            f.write(flist_html)
            f.close()
        except Exception as ee:
            print("Exception:%r"%ee)    
if __name__ == '__main__':
  tf.app.run()