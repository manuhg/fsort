//#include <GLFW/glfw3.h>
//#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <string>
#include <iostream>
#include <filesystem>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;
namespace fs=std::filesystem
using namespace cv;
vector<vector<uchar>> images;
void loadimages(string dir)
{
    for(auto &p : fs::directory_iterator(dir))
        cout<<"\n"<<p;
}
int main(int argc, char **argv) {
  if (argc < 2) {
    printf("No args! %s", argv[0]);
    return -1;
  }
  if (!glfwInit()) {
    printf("Error!");
  }
  vector<string> dirs(argv[1], end(argv));
  for (auto &i : dirs)
      loadImages(files);
  cout << "\n";
  return 1;
}
