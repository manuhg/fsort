#ifndef _LIBFSORT_H

#define _LIBFSORT_H
#ifndef CPU_ONLY
  #define CPU_ONLY
#endif

#define _ACCURACY_LOW 1
#define _ACCURACY_MEDIUM 2
#define _ACCURACY_HIGH 3

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <bhtsne/tsne.h>
using namespace std;


vector<vector<float>> extract_features(int num_img_files);

class tsne_wrapper
{
private:
    int iters, max_iters;
    vector<vector<double> > tsne_embeddings;
    vector<vector<float> > data;
    int op_dims;
    double perplexity;
    double theta;
    bool normalize;
    bool run_manually=false;
    int num_threads;

    int input_dims,samples;
    double *inp_data, *op_data;
    vector<double> min_, max_;
    int i,j,k;

public:

    vector<vector<double>>  run(vector<vector<float>> data, int op_dims=3, int max_iters=1000, int num_threads=2,double perplexity=30, double theta=0.5,double amplify=50.0, bool normalize=false);
   // vector<vector<double>>  run(vector<string> image_files, int op_dims=3, int max_iters=1000, double perplexity=30,int num_threads=2, double theta=0.5, bool normalize=false);

    void finish();
    ~tsne_wrapper();
};
vector<vector<double>> extract_embeddings(vector<string> image_files,int perplexity=30,int threads=3,bool print_tsnepts=false,float amplify=50.0,bool normalize=false);
//add option to change batch size and and crop sizes

#endif
