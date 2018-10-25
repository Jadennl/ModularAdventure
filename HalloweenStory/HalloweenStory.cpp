// HalloweenStory.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string user, demon;
bool savedFriend, hasBible;

void freeze();
void setVars();
void start();
string toCaps(string s);

int main()
{
	setVars();
	start();
}

string toCaps(string s) {
    transform(s.begin(), s.end(), s.begin(), toupper);
    return s;
}

void setVars() {
	savedFriend = false;
	hasBible = false;
	cout << "This story involves you and your friend.\n" << "What is your name?: ";
    getline(cin, user);
	cout << "What will you name your friend?: ";
    getline(cin, demon);
}

void start() {
    cout << "\n\nOctober 31st,\nYour class decided that it would be a great day to have a field trip to the local farm.\nYou and your friend " << demon 
        << " decide it is a great way to waste some time.\n" << demon << ": What do you think we will do here?" << endl;
    string input = "";
    getline(cin,input);
    cout << demon << ": Cool. I think we should ditch them.\n\n\n|THE FARM|\nThe front gate is rusted." <<
        "A cool autumn gust brushes your bare skin, you wore the wrong clothes today."
        << "\nA guide meets your class at the front of the 2 story house near the entrance of the farm."
        << "\n\nGUIDE: Welcome to Medicon Farms! I am so sorry you guys came today... \nWe just finished harvest and there is nothing on the fields."
        << "\nBefore the teacher could protest, the guide leads the group into the home and insists on\n\"Explaining the history\" of the Medicon family house.\n"
        << "\nYou and " << demon << " notice a strange door that the guide stood behind while explaining a painting across from him." << endl
        << demon << ": " << user << ", did you notice how the guide ignored that door? Should we go inside?(yes/no)\n";
    string response = "";
    getline(cin, response);
    string choice = toCaps(response);
    while (choice.find("YES") == string::npos && choice.find("NO") == string::npos) {
        cout << endl << demon << ": What? I'm asking if we should go inside... should we?";
        getline(cin, response);
        choice = toCaps(response);
    }
    if (choice.find("NO")) {
        freeze();
    }
}

void freeze() {
    if (savedFriend == true) {
    }
    else
    {
        cout << "\nYou decide not to take a risk and stay with the group.\nThe tour is rather boring, you learn about 30 types of vegetables that they grow."
            << "\nHours pass as you wander each hallway with the class, each room having \"Expansive\" history."
            << "\nIt was dark outside when another bus came to pick your class up.\nWhile driving home, the bus sputters and halts."
            << "\nThere is no service, so your class huddles together as the metal shell begins to refridgerate your bodies."
            << "\nIt was -10 degrees that night. Your cold body shivers until it could shiver no more.\nYou die of hyperthermia.";
    }
}