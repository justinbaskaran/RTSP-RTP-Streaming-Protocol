#include "opencv2/opencv.hpp"

using namespace cv;
int main(int argn, char**arg)
{
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;
    Mat edges;
    namedWindow("edges",1);

    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera

        //1. Use handleClientRequest, to handle setup
        // find play
        
        handleClientRequest(1501);
       

        if(waitKey(30) >= 0) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
