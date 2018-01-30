#include<stdio.h>
#include<opencv2/opencv.hpp>

using namespace cv;

int main(int argc,char **argv)
{
  if(argc!=2)
    {
      printf("No args!");
      return -1;
    }
  Mat image =imread(argv[1],1);
  if(!image.data)
    {
      printf("No img data");
      return -1;
    }
  namedWindow("Display Image",WINDOW_AUTOSIZE);
  imshow("Display image",image);
  waitKey(0);
  return 0;
    
}
