import os,sys
import numpy as np
import tensorflow as tf
from sklearn.manifold import TSNE as tsne

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


def get_pool_lst(dir):
  create_graph()
  pool_list=[]
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
          val_lst=sess.run(feature_tensor)[0][0][0].tolist()
          pool_list.append(val_lst)
      except Exception as e:
        print("\nException while generating pool list\n%r"%e)            
  return pool_list

def run_tsne(pool_lst):
      #
def main(_):
  if len(sys.argv) < 2:
    print("please provide a path to one or more images, e.g. images/* or images/*.jpg etc..")
    sys.exit()
  else:
    output_dir = "image_vectors"
    
    for i in range(1,len(sys.argv)):
          pool_lst=get_pool_lst(sys.argv[i])
          flst=run_tsne(pool_lst)
          try:
            f=open("flst.txt","wb")
            f.write(flst)
            f.close()
          except Exception as ee:
            print("Exception:%r"%ee)

if __name__ == '__main__':
  tf.app.run()
