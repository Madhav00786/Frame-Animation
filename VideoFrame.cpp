/**********************************************************************************************************
*Filename							VideoFrame.cpp
*Version							1.1
*Student Name						Madhav Sachdeva
*Student Number						040918899
*Course Name and Number				C++ Programming  CST8219
*Lab Section						313
*Assignment Number					3
*Due Date							November 30,2019
*Submission Date					November 30,2019
*Professor's Name					Marius Makos
*Purpose							This file contains the basic initialisation and function of a VideoFrame.
***********************************************************************************************************/

//VideoFrame.cpp
#define _CRT_SECURE_NO_WARNINGS

//#include "Animation.h"
//#include "AnimationManager.h"
#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
//#include <time.h>
//#include <vector>
//#include <forward_list>
using namespace std;
#include "Frame.h"
#include "VideoFrame.h"



/***************************************************************************
Function Name				CalculateFrameResource
Purpose						calculating data for printing out
Function In parameters		none
Function Out parameters		none
Version						1.1
Student Name				Madhav Sachdeva
****************************************************************************/
void VideoFrame::CalculateFrameResource() {
	cout << "\nVideoFrame: " << static_cast<Frame&>(*this);
	cout << "\nLempel-Ziv-Welch Lossless Compression\n";
	cout << "-----------------------------------------------------------------------------------------------\n";
	cout << "colours: \t";
	for (int i = 1; i <= 8; i++) {
		cout << "|" << fixed << setprecision(0) << pow(2,i) << "\t";
	}
	cout<<"\n-----------------------------------------------------------------------------------------------\n";
	/////Will check again just for making sure that some output is coming
	cout << "file size (MB): ";
	for (int i = 0; i < 8; i++) {
		cout << "|" <<fixed<<setprecision(2)<< size / (COMPRESSION_RATIO*BITDEPTH_FACTOR[i]) << "\t";
	}
	cout<<"\n-----------------------------------------------------------------------------------------------\n";
}

/***************************************************************************
Function Name				operator<<
Purpose						overloading a stream operator for printing out
Function In parameters		ostream& output, VideoFrame& frame
Function Out parameters		ostream&
Version						1.1
Student Name				Madhav Sachdeva
****************************************************************************/
ostream& operator<<(ostream& output, VideoFrame& frame) {
	output << "frameName = " << static_cast<VideoFrame&>(frame) << "; duration = " << frame.size << "\n";
	return output;
}
