#include "opencv2/opencv.hpp"
#include "frames.h"
#include <iostream>
#include <highgui.h>

using namespace std;
using namespace cv;

int main(int argn, char**arg)
{
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;
    //Mat edges;
    namedWindow("edges",1);




   int frame_width=   cap.get(CV_CAP_PROP_FRAME_WIDTH);
   int frame_height=   cap.get(CV_CAP_PROP_FRAME_HEIGHT);
   VideoWriter video("out.Mjpeg",CV_FOURCC('M','J','P','G'),10, Size(frame_width,frame_height),true);



// Create socket for incoming connections
int server_socket =setupServerTCPSocket("1501");
if (server_socket < 0){
  printf("setupServerTCPSocket() failed");
  exit(0);
}
for(;;)
    {
      Mat frame;
      cap >> frame; // get a new frame from camera
      imshow( "edges", frame);
      video.write(frame);
    //
    // int client_socket = acceptTCPConnection(server_socket);
    //
    //     //Create seperate memory for client argument
    //     THREAD_ARGUMENTS *thread_args = (THREAD_ARGUMENTS*)malloc(sizeof(THREAD_ARGUMENTS));
    //     if (thread_args == NULL){
    //       printf("cannot malloc memory for _thread_arguments structure!");
    //       exit(0);
    //     }
    //
    //     //Pass the arguments to client socket
    //     thread_args->client_socket = client_socket;
    //
    //     //Create client thread
    // 		pthread_t thread_id;			//thread id number
    // 		int return_value = pthread_create(&thread_id, NULL, threadMain, thread_args);
    // 		if (return_value != 0){
    //       printf("Line 39 failed");
    //       exit(0);
    // 		}
    // 		//Output the thread id
    // 		printf("with thread %lu\n", (unsigned long int)thread_id);


      //  imshow( "edges", frame);
        //1. Use handleClientRequest, to handle setup
        // find play




        if(waitKey(30) >= 0) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
