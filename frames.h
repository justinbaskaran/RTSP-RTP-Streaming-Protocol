#include "opencv2/opencv.hpp"
#include <iostream>
#include <arpa/inet.h>
#include <pthread.h>




using namespace cv;
using namespace std;

extern "C" {

#include "server/Server.h"
#include "server/AddressUtility.c"
#include "server/DieWithMessage.c"
#include "server/FileUtility.c"
#include "server/HandleRequestUtility.c"
#include "server/RTPPacketUtility.c"
#include "server/SendUtility.c"
#include "server/ServerUtility.c"
#include "server/StringUtility.c"
#include "server/Thread.c"
#include "server/TimeUtility.c"



}
