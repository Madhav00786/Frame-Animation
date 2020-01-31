/*******************************************************************************
*Filename							Animation.cpp
Version								1.1
*Student Name						Madhav Sachdeva
*Student Number						040918899
*Course Name and Number				C++ Programming  CST8219
*Lab Section						313
*Assignment Number					3
*Due Date							November 30,2019
*Submission Date					November 30,2019
*Professor's Name					Marius Makos
*Purpose							This file contains the working of a Frame.
********************************************************************************/
//Animation.cpp
#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <string>
#include <time.h>
#include <forward_list>
using namespace std;

#include "Frame.h"
#include "AudioFrame.h"
#include "VideoFrame.h"
#include "Animation.h"
//#include "AnimationManager.h"






/*****************************************************
Function Name				EditFrame
Purpose						Editing a frame
Function In parameters		none
Function Out parameters		none
Version						1.1
Student Name				Madhav Sachdeva
*****************************************************/
void Animation::EditFrame() {
	short i = 0, y = 0;
	char fName[100];
	int dur;
	
	int counter = 0;

	cout << "Edit a frame in the Animation \n";
	if (frames.empty()) {//checking if animation is still empty or not
		cout << "This are no Frames in the Animation.";
	}
	else {
		for (auto i = frames.begin(); i != frames.end(); ++i) {
			//cout << "Frame #" << i << "file name = " << counter->GetpNext()->GetFrameName();
			counter++;
			//i++;
		}

		cout << "There are " << counter << " Frame(s) in the list. Please specify the index (<=" << counter - 1 << ") to edit at : ";
		cin >> y;
		while ((y < 0) || (y > (counter - 1))) {
			cin.clear();
			cout << "Please enter valid index: ";
			cin >> y;
		}

		//counter = frames;
		forward_list<Frame*>::iterator itr;
		itr = frames.begin();
		for (int i = 0; i < y; i++) {
			++itr;
		}



		cout << "The name and duration of this Frame are " << **itr << " What do you wish to replace them with? " << endl;
		cout << "Enter new frame name: ";
		cin >> fName;
		cout << "Enter new size: ";
		cin >> dur;
		//AudioFrame* aframe;
		//VideoFrame* vframe;
		//*itr.
		//(*itr)->CalculateFrameResource();
		//frames.emplace_after(itr, );//no new needed
		AudioFrame* frame;
		if (frame=dynamic_cast<AudioFrame*>(*itr)) {
			
			**itr = AudioFrame(fName, dur);
		}
		else {
			
			**itr = VideoFrame(fName, dur);
		}
		//frame = new AudioFrame(name, dur);

		
		//break;

		/*if (y == 0) {//if y=0 it should erase after before begin
			itr = frames.before_begin();
		}
		else {//if y==1 it should erase after begin
			itr = frames.begin();
			for (int i = 0; i < y - 1; i++) {
				++itr;
			}
		}
		itr = frames.erase_after(itr);
		*///frames.
		//delete  *itr;
		cout << "Frame #" << y << " edit complete\n";
	}

}


/*****************************************************
Function Name				DeleteFrame
Purpose						Deleting a frame
Function In parameters		none
Function Out parameters		none
Version						1.1
Student Name				Madhav Sachdeva
*****************************************************/
void Animation::DeleteFrame() {
	frames.pop_front();

	cout << "First Frame deleted\n";
}

/***********************************************************************************
Function Name				operator>>
Purpose						overloading a stream operator for getting in typed data
Function In parameters		istream& input, Animation& animation
Function Out parameters		istream&
Version						1.1
Student Name				Madhav Sachdeva
*************************************************************************************/
istream& operator>>(istream& input, Animation& animation) {


	string name;
	int dur = 0;
	string fType;

	cout << "Insert a Frame in the Animation \nPlease enter the Frame frameName: ";
	input >> name;
	cout << "Please enter the Frame size(MB): ";
	input >> dur;

	//for (it = RA.frames.begin(); it != RA.frames.end(); it++) {
		//(*it)->CalculateFrameResource();
	//}
	Frame* frame;
	while (true) {
		cout << "Please enter the Frame type (AudioFrame=A, VideoFrame=V): ";
		input >> fType;
		if (fType == "A") {
			frame = new AudioFrame(name, dur);

			animation.frames.push_front(frame);
			break;
		}
		else if (fType == "V") {
			frame = new VideoFrame(name, dur);
			animation.frames.push_front(frame);
			break;
		}
		else {
			cout << "Enter valid option\n";
		}
	}
	//delete[] frame;
	cout << "Frame " << name << " Frame* added at the front of frames";
	return input;

}



/***************************************************************************
Function Name				operator<<
Purpose						overloading a stream operator for printing out
Function In parameters		ostream& output, Animation& animation
Function Out parameters		ostream&
Version						1.1
Student Name				Madhav Sachdeva
****************************************************************************/
ostream& operator<<(ostream& output, Animation& animation) {
	output << "Animation name is " << animation.animationName << "\n  \tReport the Animation\n";
	if (animation.frames.empty()) {
		output << "\tNo frames in the Animation \n";
	}
	else {
		int counter = 0;
		forward_list<Frame*>::iterator itr;
		//for (it = RA.frames.begin(); it != RA.frames.end(); it++) (*it)->CalculateFrameResource()


		for (itr = animation.frames.begin(); itr != animation.frames.end(); itr++) {
			output << "\nFrame #" << counter++ ;
			(*itr)->CalculateFrameResource();//output through operator overloading of Frame operator<<
		}
	}
	return output;
}




Animation::~Animation() {
	//DeleteFrame();
	//delete (frames&);
	{
		forward_list<Frame*>::iterator it;
		for (it = frames.begin(); it != frames.end(); it++)
			delete* it;
	}
}