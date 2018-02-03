#include <GLFW/glfw3.h>
#include <opencv2/opencv.hpp>
#include <stdio.h>

using namespace cv;

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("No args!");
    return -1;
  }
  if (!glfwInit()) {
    printf("Error!");
  }
  Mat image = imread(argv[1], 1);
  if (!image.data) {
    printf("No img data");
    return -1;
  }
  //namedWindow("Display Image", WINDOW_AUTOSIZE);
  imshow(argv[1], image);
  waitKey(0);
  return 0;
}
