/**********************************************************************************************************
*Filename							AudioFrame.cpp
*Version							1.1
*Student Name						Madhav Sachdeva
*Student Number						040918899
*Course Name and Number				C++ Programming  CST8219
*Lab Section						313
*Assignment Number					3
*Due Date							November 30,2019
*Submission Date					November 30,2019
*Professor's Name					Marius Makos
*Purpose							This file contains the basic initialisation and function of a AudioFrame.
***********************************************************************************************************/
//AudioFrame.cpp
#define _CRT_SECURE_NO_WARNINGS

//#include "Animation.h"
//#include "AnimationManager.h"
#include <iostream>
#include <string>
#include <iomanip>
//#include <time.h>
//#include <vector>
//#include <forward_list>
using namespace std;
#include "Frame.h"
#include "AudioFrame.h"



/***************************************************************************
Function Name				CalculateFrameResource
Purpose						calculating data for printing out
Function In parameters		none
Function Out parameters		none
Version						1.1
Student Name				Madhav Sachdeva
****************************************************************************/
void AudioFrame::CalculateFrameResource() {

	//float fSize;

	cout << "\nAudioFrame: " << static_cast<Frame&>(*this);
	cout << "\nMP3 Lossy Compression\n";
	cout << "-----------------------------------------------------------------------------------------------\n";
	cout << "bitrate(kbits/s): \t";
	for (int i = 0; i < 3; i++) {
		cout << "|" <<fixed<<setprecision(0)<< BITRATE[i] << "\t";
	}
	cout << "\n-----------------------------------------------------------------------------------------------\n";

	cout << "file size (MB):  \t";
	for (int i = 0; i < 3; i++) {
		cout << "|" <<fixed<<setprecision(2)<< size / COMPRESSION_RATIO[i] << "\t";
	}
	cout << "\n-----------------------------------------------------------------------------------------------\n";

}

/***************************************************************************
Function Name				operator<<
Purpose						overloading a stream operator for printing out
Function In parameters		ostream& output, AudioFrame& frame
Function Out parameters		ostream&
Version						1.1
Student Name				Madhav Sachdeva
****************************************************************************/
ostream& operator<<(ostream& output, AudioFrame& frame) {
	output << "frameName = " << static_cast<AudioFrame&>(frame) << "; duration = " << frame.size << "\n";
	return output;
}