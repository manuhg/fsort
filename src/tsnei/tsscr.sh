# create virtual environment using python 3.5 with name '3.5'
conda create -n 3.5 python=3.5

# activate the virtual environment
source activate 3.5

# install tensorflow
conda install -c conda-forge tensorflow

# download the original script
wget https://raw.githubusercontent.com/tensorflow/models/master/tutorials/image/imagenet/classify_image.py

# download a sample image
wget http://thecatapi.com/api/images/get?type=jpg -O cat.jpg

# run the script to generate text labels for an input image
python classify_image.py cat.jpg

# get the full updated script
wget 
https://gist.githubusercontent.com/duhaime/2a71921c9f4655c96857dbb6b6ed9bd6/raw/0e72c48e698395265d029fabad0e6ab1f3961b26/classify_images.py

# install the new dependency inside your virtual environment
pip install psutil

# download a collection of jpg images (or use one you have)
wget https://goo.gl/Lf9vmN -O images.tar.gz
tar -zxf images.tar.gz

# run the script on a glob of images
python classify_images.py "images/*"


#wget http://douglasduhaime.com/assets/posts/similar-images/utils/cluster_vectors.py
#pip install annoy && pip install scipy && pip install nltk
#python cluster_vectors.py
wget http://douglasduhaime.com/assets/posts/similar-images/utils/get_tsne_vector_projections.py
python get_tsne_vector_projections.py

