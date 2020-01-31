/**********************************************************************************************************
*Filename							Frame.cpp
*Version							1.1
*Student Name						Madhav Sachdeva
*Student Number						040918899
*Course Name and Number				C++ Programming  CST8219
*Lab Section						313
*Assignment Number					3
*Due Date							November 30,2019
*Submission Date					November 30,2019
*Professor's Name					Marius Makos
*Purpose							This file contains the basic initialisation and function of a Frame.
***********************************************************************************************************/
//Frame.cpp
#define _CRT_SECURE_NO_WARNINGS
//#include "Animation.h"
//#include "AnimationManager.h"
#include <iostream>
#include <string>
using namespace std;
//#include <time.h>
//#include <vector>
//#include <forward_list>
#include "Frame.h"


/***************************************************************************
Function Name				operator<<
Purpose						overloading a stream operator for printing out
Function In parameters		ostream& output, Frame& frame
Function Out parameters		ostream&
Version						1.1
Student Name				Madhav Sachdeva
****************************************************************************/
ostream& operator<<(ostream& output, Frame& frame) {
	output << "frameName = " << frame.frameName;
	return output;
}