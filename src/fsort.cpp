#include <GLFW/glfw3.h>
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;
using namespace cv;
vector<vector<uchar>> images;
void loadImages(vector<string> files) {
  int a,n = files.size();
  cout << "\nNo of files: " << n;
  // for (int i = 0; i < n; i++)
  //   cout << "\n" << files[i];

  for (int i = 0; i < n; i++) {
    cout << "\nLoading File:" << files[i] << " => ";
    Mat im = imread(files[i], 1);
    images.reserve(n);
    if (!im.data) {
      printf("No image data");

    } else {
      vector<uchar> tmpVec;
      printf("Extracting pixel data...");
      if (im.isContinuous()) {
        cout << "\nImage file is continuos";
        tmpVec.assign(im.datastart, im.dataend);
      } else {
        cout << "\nImage file is not continuos";
        for (int j = 0; j < im.rows; j++)
          tmpVec.insert(images[i].end(), im.ptr<uchar>(j), im.ptr<uchar>(j) + im.cols);
      }
      images.push_back(tmpVec);
      
    }
    cout<<endl<<images[i].data();
    // im.total()*im.channels()
  }
  int fd=open("dump.data",O_WRONLY|O_CREAT);
  if(fd==-1)
    perror("open");
  else
    {
      int bytes=0;
      //write(fd,im.data,im.)
    }
  // ofstream dDfile("dump.data",ios::binary|ios::out);
  // ostream_iterator<vector<vector<uchar>>> opIt(dDfile);
  // copy(images.begin(),images.end(),opIt);
  // #ifdef _trytoprint
  // cout << "\nImage data";
  // for (int i = 0; i < images.size(); i++) {
  //   for (int j = 0; j < images[i].size(); j++)
  //     printf("%x%s",images[i][j],(j%64==0)?"\n":"");
  //   printf("\n");
  // }
  // #endif
}
int main(int argc, char **argv) {
  if (argc < 2) {
    printf("No args! %s", argv[0]);
    return -1;
  }
  if (!glfwInit()) {
    printf("Error!");
  }
  // Mat image = imread(argv[1], 1);

  // if (!image.data) {
  //   printf("No img data");
  //   return -1;
  // }
  vector<string> files(argv + 1, argv + argc);
  loadImages(files);
  // namedWindow("Display Image", WINDOW_AUTOSIZE);
  // printf("\nData:\n");
  // for(int i=0;i<=((image.cols*image.rows)-2);i++)
  //  printf("%s%x",(i%64==0)?"\n":"",image.data[i]);
  // imshow(argv[1], image);
  waitKey(0);
  cout << "\n";
  return 1;
}
