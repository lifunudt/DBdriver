/*************************************************************************
	> File Name: datatype.h
	> Author: 
	> Mail: 
	> Created Time: 二  5/ 3 10:21:08 2016
 ************************************************************************/

#ifndef _DATATYPE_H
#define _DATATYPE_H
#endif

#include <iostream>
#include <cstring>
#include <cmath>
#include <cv.h>
#include <highgui.h>

using namespace std;
using namespace cv;

struct Signature {
    int id;
    int mapid;
    double stamp;
    int weight;
    cv::Mat image;
};
struct VisualWord {
    int VWid;
};
struct Link{
    int linkid;
};
struct VWDictionary{
    int VWDid;
};
struct Transform{
    int tfid;
};

