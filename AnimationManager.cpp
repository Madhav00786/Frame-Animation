/*************************************************************************************
*Filename							AnimationManager.cpp
Version								1.1
*Student Name						Madhav Sachdeva
*Student Number						040918899
*Course Name and Number				C++ Programming  CST8219
*Lab Section						313
*Assignment Number					3
*Due Date							November 30,2019
*Submission Date					November 30,2019
*Professor's Name					Marius Makos
*Purpose							This file contains the working of an Animation.
**************************************************************************************/
//AnimationManager.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <forward_list>

using namespace std;

#include "Frame.h"
#include "Animation.h"
#include "AnimationManager.h"



/*****************************************************
Function Name				EditAnimation
Purpose						Editing an animation
Function In parameters		none
Function Out parameters		none
Version						1.1
Student Name				Madhav Sachdeva
*****************************************************/
void AnimationManager::EditAnimation() {
	int counter = 0, y = 0;
	if (animations.empty()) {//checking if animation is still empty or not
		cout << "No animations added.";
	}
	else {
		for (auto i = animations.begin(); i != animations.end(); ++i) {//i is iterator
			counter++;
		}
		cout << "Which Animation do you wish to edit? Please give the index (from 0 to " << counter - 1 << "): ";
		cin >> y;
		while ((y < 0) || (y > (counter - 1))) {
			cin.clear();
			cout << "Please enter valid index: ";
			cin >> y;
		}
		cout << "Editing Animation #" << y;



		char response;
		bool RUNNING = true;

		Animation& A = this->animations.at(y);
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

		while (RUNNING)
		{
			cout << "\nMENU\n 1. Insert a Frame at front\n 2. Delete first Frame\n 3. Edit a Frame\n 4. Quit" << endl;
			cin >> response;
			switch (response)
			{
			case '1':cin >> A; break;
			case '2':A.DeleteFrame(); break;
			case '3':A.EditFrame(); break;
				//case '4':cout << A; break;
			case '4':RUNNING = false;
				cout << "Animation #" << y << " edit complete\n";
				break;
			default:cout << "Please enter a valid option" << endl;
			}
		}
	}
}


/*****************************************************
Function Name				DeleteAnimation
Purpose						Deleting an animation at particular index
Function In parameters		none
Function Out parameters		none
Version						1.1
Student Name				Madhav Sachdeva
*****************************************************/
void AnimationManager::DeleteAnimation() {
	int counter = 0, y = 0;
	if (animations.empty()) {//cehcking if animation is still empty or not
		cout << "No animations added. \n";
	}
	else {
		for (auto i = animations.begin(); i != animations.end(); ++i) {
			//cout << "Frame #" << i << "file name = " << counter->GetpNext()->GetFrameName();
			counter++;
			//i++;
		}
		cout << "Delete an Animation from the Animation Manager \n";
		cout << "Which Animation do you wish to delete?";
		cout << " Please give the index 0 to " << counter - 1 << "): ";
		cin >> y;
		while ((y < 0) || (y > (counter - 1))) {
			cin.clear();
			cout << "Please enter valid index: ";
			cin >> y;
		}
		animations.erase(animations.begin() + y);
		cout << "Animation #" << y << " deleted" << endl;

	}

}
// add an Animation



/*****************************************************************************************
Function Name				operator>>
Purpose						overloading a stream operator for getting in typed data
Function In parameters		istream& input, AnimationManager& manager
Function Out parameters		istream&
Version						1.1
Student Name				Madhav Sachdeva
******************************************************************************************/
istream& operator>>(istream& input, AnimationManager& manager) {
	string name;

	cout << "Add an Animation to the Animation Manager \nPlease enter the Animation Name: ";
	input >> name;

	manager.animations.push_back(Animation(name));
	cout << "Animation " << name << " added at the back of animations \n";


	return input;
}


// output the Animations
/***************************************************************************
Function Name				operator<<
Purpose						overloading a stream operator for printing out
Function In parameters		ostream& output, AnimationManager& manager
Function Out parameters		ostream&
Version						1.1
Student Name				Madhav Sachdeva
****************************************************************************/
ostream& operator<<(ostream& output, AnimationManager& manager) {
	if (manager.animations.empty()) {
		output << "Manager is empty";
	}
	else {
		int counter = 0;
		vector<Animation>::iterator itr;
		output << "AnimationManager: " << manager.managerName << "\n";
		for (itr = manager.animations.begin(); itr != manager.animations.end(); itr++) {
			output << "Animation: " << counter++ << "\n \t" << *itr;//output through operator overloading of Animation
		}
	}
	return output;

}