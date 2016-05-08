/*************************************************************************
	> File Name: dispalyimage.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  5/ 8 22:12:28 2016
 ************************************************************************/

#include <iostream>
#include <cv.h>
#include <highgui.h>
using namespace std;
using namespace cv;
 
int main( int argc, char** argv ){
    Mat image;
    image = imread( argv[1], 1 );
    namedWindow("Display Image", CV_WINDOW_AUTOSIZE);
    imshow("Display Image", image);
    waitKey(0);
    cout<<"hello world!"<<endl;
    return 0;
}

