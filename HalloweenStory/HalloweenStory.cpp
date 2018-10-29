// HalloweenStory.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
using namespace std;

string user, demon;
bool savedFriend, hasBible;

void setVars();
void friendKill(int deathCode);
void freeze();
void start();
void possessFriend(string reason);
string toCaps(string s);

int main()
{
	srand(time(NULL));
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
		<< " decide it is a great way to waste some time.\n\n" << demon << ": What do you think we will do here?" << endl;
	string input = "";
	getline(cin, input);
	cout << endl << demon << ": Cool. I think we should ditch them.\n\n\n|THE FARM|\nThe front gate is rusted."
		<< "A cool autumn gust brushes your bare skin, you wore the wrong clothes today."
		<< "\nA guide meets your class at the front of the 2 story house near the entrance of the farm."
		<< "\n\nGUIDE: Welcome to Medicon Farms! I am so sorry you guys came today... \nWe just finished harvest and there is nothing on the fields."
		<< "\nBefore the teacher could protest, the guide leads the group into the home and insists on\n\"Explaining the history\" of the Medicon family house.\n"
		<< "\nYou and " << demon << " notice a strange door that the guide stood behind while explaining a painting across from him." << endl
		<< endl << demon << ": " << user << ", did you notice how the guide ignored that door? Should we go inside? ";
	string response = "";
	getline(cin, response);
	string choice = toCaps(response);
	while (choice.find("YES") == string::npos && choice.find("YEAH") == string::npos && choice.find("NO") == string::npos && choice.find("NAH") == string::npos) {
		cout << endl << demon << ": What? This is a literally a yes or no question. Should we?\t";
		getline(cin, response);
		choice = toCaps(response);
	}
	if (choice.find("NO") != string::npos) {
		freeze();
	}
	else {
		possessFriend(input);
	}
}

void freeze() {
	cout << "\nYou decide not to take a risk and stay with the group.\nThe tour is rather boring, you learn about 30 types of vegetables that they grow."
		<< "\nHours pass as you wander each hallway with the class, each room having \"Expansive\" history."
		<< "\nIt was dark outside when another bus came to pick your class up.\nWhile driving home, the bus sputters and halts."
		<< "\nThere is no service, so your class huddles together as the metal shell begins to refridgerate your bodies...\n";
	cin.ignore();
	cout << "\nIt was -10 degrees that night. Your cold body shivers until it could shiver no more.\nYOU DIE OF HYPOTHERMIA.\n";
}

void possessFriend(string reason) {
	cout << "\nYou and your friend go into the bathroom and wait until the group heads into a different hallway."
		<< "\nYou and " << demon << " open the hidden door. You have to crawl into the room.\nThe room looks older than the resto of the building,"
		<< " it's as if it wasnt renovated with the rest.\nThere is a large book standing on a pedestal, it has the words \"MEDICON\" embrossed in gold"
		<< " on the cover. " << demon << " blows on the cover and opens it.\n" << endl;
	if (reason.size() > 0) {
		cout << demon << ": " << user << ", look at that it says you said on the bus!\n" << endl << "The words \"" << reason << "\" are written in red on the first page.";
	}
	cout
		<< "\nEach page contains all the words and phrases said here on the farm.\nYou learn about the drug smuggling that takes place during the harvest.\n"
		<< "More and more secrets about the farm are revealed until " << demon << " flips the page again and immediatly stops moving.\n"
		<< "Confused, you get closer. " << demon << " begins to shake and foam at the mouth, hissing.";
	string choice = "";
	do {
		cout << endl << "Do you crawl away or help?: ";
		getline(cin, choice);
		choice = toCaps(choice);
	} while (choice.find("CRAWL") == string::npos && choice.find("RUN") == string::npos && choice.find("HELP") == string::npos);
	if (choice.find("HELP") != string::npos) {
		cout << "You aproach " << demon << "..." << endl;
		cin.ignore();
		friendKill(rand() % 5);
	}
}

void friendKill(int deathCode) {
	if (deathCode == 0) {
		cout << demon << " grabs you by the throat. You try to remove " << demon << "'s hand, but it is too strong.\n"
			<< "You begin to shake, your watering eyes are trying to let air into your body by pushing out.\n"
			<< "Your throat burns as your windpipe gets crushed. You thrash and thrash until your body runs out of oxygen."
			<< "\nYOU DIED." << endl;
	}
	else if (deathCode == 1) {
		cout << demon << " punches you in the face. Before you can react, " << demon << " bashes your face in."
			<< "\nYour face is mashed in over and over again until you can no longer feel your face."
			<< "\nBlood spills all over the floor, your lifeless body twitches as " << demon << " continues to pulverize the mash that was once your head."
			<< "\nYOU DIED." << endl;
	}
	else if (deathCode == 2) {
		cout << demon << " breaks a nearby sharp object and stabs you in the chest. You immediatly cough up blood."
			<< "\nBlood begins to spill out of your chest as " << demon << " removes the object and stabs you again,";
		cin.ignore();
		cout << "and again...";
		cin.ignore();
		cout << "and again...\nYOU DIED.\n";
	}
	else if (deathCode == 3) {
		cout << "4";
	}
	else {
		cout << "5";
	}
} 