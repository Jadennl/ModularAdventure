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
void freeze(bool early);
void start();
void runEntrance();
void mainHall();
void upstairs();
void goRoom();
void jump();
void hide(bool closet);
void leave();
void exorcise();
void saveFriend();
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
	cout << "\nAs you have noticed, you type responses.\nIf there is not a question but the story pauses, hit enter."
		<< "\nHit enter to continue...";
	cin.ignore();
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
		<< endl << demon << ": " << user << ", did you notice how the guide ignored that door? Should we go inside? (yes/no): ";
	string response = "";
	getline(cin, response);
	string choice = toCaps(response);
	while (choice.find("YES") == string::npos && choice.find("YEAH") == string::npos && choice.find("NO") == string::npos && choice.find("NAH") == string::npos) {
		cout << endl << demon << ": What? This is a literally a yes or no question. Should we?\t";
		getline(cin, response);
		choice = toCaps(response);
	}
	if (choice.find("NO") != string::npos) {
		freeze(true);
	}
	else {
		possessFriend(input);
	}
}

void freeze(bool early) {
	if (early == true) {
		cout << "\nYou decide not to take a risk and stay with the group.\nThe tour is rather boring, you learn about 30 types of vegetables that they grow."
			<< "\nHours pass as you wander each hallway with the class, each room having \"Expansive\" history."
			<< "\nIt was dark outside when another bus came to pick your class up.\nWhile driving home, the bus sputters and halts."
			<< "\nThere is no service, so your class huddles together as the metal shell begins to refridgerate your bodies...\n";
	}
	cin.ignore();
	cout << "\nIt was -10 degrees that night. Your cold body shivers until it could shiver no more.\nYOU DIE OF HYPOTHERMIA.\n";
}

void possessFriend(string reason) {
	cout << "\nYou and your friend go into the bathroom and wait until the group heads into a different hallway."
		<< "\nYou and " << demon << " open the hidden door. You have to crawl into the room.\nThe room looks older than the rest of the building,"
		<< " it's as if it wasnt renovated with the rest.\nThere is a large book standing on a pedestal, it has the words \"MEDICON\" embrossed in gold"
		<< " on the cover. " << demon << " blows on the cover and opens it.\n" << endl;
	if (reason.size() > 0) {
		cout << demon << ": " << user << ", look at that it says you said on the bus!\n" << endl << "The words \"" << reason << "\" are written in red on the first page.";
	}
	cout
		<< "\nEach page contains all the words and phrases said here on the farm.\nYou learn about the drug smuggling that takes place during the harvest.\n"
		<< "More and more secrets about the farm are revealed until " << demon << " flips the page again and stops moving.\n"
		<< "Confused, you get closer. " << demon << " begins to shake and foam at the mouth, hissing.";
	string choice = "";
	do {
		cout << endl << "Do you crawl away or help?: ";
		getline(cin, choice);
		choice = toCaps(choice);
	} while (choice.find("CRAWL") == string::npos && choice.find("LEAVE") == string::npos
		&& choice.find("HELP") == string::npos && choice.find("GO") == string::npos);
	if (choice.find("HELP") != string::npos) {
		cout << "You aproach " << demon << "..." << endl;
		cin.ignore();
		friendKill(rand() % 5);
	}
	else {
		runEntrance();
	}
}

void runEntrance() {
	cout << endl << "While " << demon << " is convulsing, you crawl through the small entrance and close the door."
		<< "\nThe air feels different in the house; it looks more abandoned. You look at the grandfather clock on the wall, it is 1:00am now."
		<< "\nHow did the teacher forget about you and " << demon << "?\nYou walk to the front door of the house.";
	string choice = "";
	do {
		cout << "Do you leave the house or stay?: ";
		getline(cin, choice);
		choice = toCaps(choice);
	} while (choice.find("LEAVE") == string::npos && choice.find("STAY") == string::npos);
	if (choice.find("LEAVE") != string::npos) {
		leave();
	}
	else {
		mainHall();
	}
}

void leave() {
	if (hasBible == true && savedFriend == false) {
		cout << "\nYou run to the front gate. Before you can exit you see " << demon << " waiting for you."
			<< endl << endl << demon << ": Forgetting someone? :-)";
		friendKill(6);
	}
	else if (hasBible == false) {
		cout << "\nYou run to the front gate. You run out of the farm and onto the road.\nYou walk for hours on end; the cold wind cuts your entire body.";
		freeze(false);
	}
	else {
		cout << "\nYou and " << demon << " approach the front gate." << endl
			<< endl << demon << ": Damn, that that was crazy " << user << ", so I really was possesed and I tried to kill you?";
		cin.ignore();
		cout << endl << "You both walk through the front gate; the sun is starting to rise. You see a Medicon truck drive by and you wave it down.\n"
			<< "The truck picks you both up and drives you to the visitor center where you can call the school." << "\nAll is well...\n";
		cin.ignore();
		cout << "\nYOU WIN\n";
		exit(0);
	}
}

void mainHall() {
	cout << "\nYou turn around and examine the house. The door you and " << demon << " went in is slightly ajar. You continue to look around and see a staricase.";
	string choice = "";
	do {
		cout << "\nDo you go back into the room or go upstairs?: ";
		getline(cin, choice);
		choice = toCaps(choice);
	} while (choice.find("ROOM") == string::npos && choice.find("UP") == string::npos
		&& choice.find("LEAVE") == string::npos && choice.find("BACK") == string::npos);
	if (choice.find("ROOM") != string::npos || choice.find("BACK") != string::npos) {
		cout << "\n You open the door and crawl back in...";
		cin.ignore();
		friendKill(rand() % 5);
	}
	else {
		upstairs();
	}
}

void upstairs() {
	cout << "\nYou walk up the stairs. Each step creaks as you lift your foot from it.\nWhen you reach upstairs you see a closet door and an open room."
		<< "You hear laughing from downstairs and you hide behind a corner. You see legs pacing back and forth.";
	string choice = "";
	do {
		cout << endl << "Looks like " << demon << " is getting ready to come upstairs, do you hide in the closet or in the room?: ";
		getline(cin, choice);
		choice = toCaps(choice);
	} while (choice.find("ROOM") == string::npos && choice.find("CLOSET") == string::npos && choice.find("LEAVE") == string::npos);
	if (choice.find("ROOM") != string::npos) {
		goRoom();
	}
	else if (choice.find("CLOSET") != string::npos) {
		hide(true);
	}
	else {
		cout << "\nConfused, you head back downstairs...";
		cin.ignore();
		friendKill(rand() % 5);
	}
}

void goRoom() {
	hasBible = true;
	cout << "\nYou tiptoe into the room and close the door. The room has a small bed next to an open window.\nYou can hear " << demon
		<< "'s footsteps get closer and closer.\nYou see a bible on a nightstand and take it."
		<< "\nIt sounds like " << demon << "is on the same floor as you; your heart is beating loudly.";
	string choice = "";
	int time = 3;
	do {
		cout << "\nYou need to react fast. Do you hide under the bed or jump out the window?: ";
		getline(cin, choice);
		choice = toCaps(choice);
		time--;
	} while (choice.find("JUMP") == string::npos && choice.find("HIDE") == string::npos && time > 0);
	if (time <= 0) {
		friendKill(5);
	}
	else if (choice.find("JUMP") != string::npos) {
		jump();
	}
	else {
		hide(false);
	}
}

void hide(bool closet) {
	cout << "\nYour quick thinking allows you to hide. You slow down your breath and stay completly still. You hear " << demon << " says \"Come out "
		<< user << "... I need your blood to be free...\"";
	cin.ignore();
	cout << "\nYou hear the footsteps head downstairs and a door open.";
	if (closet == true) {
		string choice = "";
		cout << "\nYou step back into the hallway. The door to the room is still open. Do you go in?(yes/no): ";
		getline(cin, choice);
		choice = toCaps(choice);
		if (choice.find("YES") != string::npos) {
			cout << "\nYou go into the room and find a bible in it. You pick it up.";
			hasBible = true;
		}
		else {
			cout << "\nYou decide to not go into the room.";
		}
	}
	cout << "\nThere is nothing left upstairs. You check for movement downstairs and there is none, so you head back downstairs."
		<< "\nThe door you and " << demon << " went through earlier looks different... there is a set of stairs now.";
	cin.ignore();
	string choice = "";
	do {
		cout << "\nDo you go downstairs or leave?: ";
		getline(cin, choice);
		choice = toCaps(choice);
	} while (choice.find("DOWN") == string::npos && choice.find("LEAVE") == string::npos);
	if (choice.find("DOWN") != string::npos) {
		exorcise();
	}
	else {
		leave();
	}
}

void jump() {
	cout << "\nHigh on adrenaline, you jump out the window. You hear a crack when you land.\nYou limp your way to the front."
		<< " Cellar doors are open, inviting you to go outside.";
	string choice = "";
	do {
		cout << "\nYou have enough energy to crawl away. Do you leave or go into the cellar?: ";
		getline(cin, choice);
		choice = toCaps(choice);
	} while (choice.find("CELLAR") == string::npos && choice.find("LEAVE") == string::npos);
	if (choice.find("CELLAR") != string::npos) {
		exorcise();
	}
	else {
		leave();
	}
}

void exorcise() {
	cout << "\nYou go down the stairs. The air becomes cold and dry.";
	if (hasBible == false) {
		cout << " You see " << demon << " at the bottom of the stairs.";
		friendKill(rand() % 5);
	}
	cout << " You notice the bible has certian pages tabbed; they are for exorcism." << "\nWhen you reach the end of the concrete stairs, " << demon
		<< " is waiting for you.\nYou figure out the reason the pages are tabbed and you begin to speak them."
		<< endl << demon << " begins to shake and thrash, you speak the words on the bible and " << demon << " screams.";
	string choice = "";
	int time = 3;
	do {
		cout << endl << demon << " stops moving. " << demon << " collapses to the floor. Do you approach " << demon << " or continue speaking?: ";
		getline(cin, choice);
		choice = toCaps(choice);
		time--;
	} while (choice.find("APPORACH") == string::npos && choice.find("CONTINUE") == string::npos
		&& choice.find("SPEAK") == string::npos && choice.find("LEAVE") == string::npos && time > 0);
	if (time <= 0) {
		friendKill(rand() % 5);
	}
	else if (choice.find("CONTINUE") != string::npos || choice.find("SPEAK") != string::npos) {
		saveFriend();
	}
	else if (choice.find("APPORACH") != string::npos) {
		friendKill(rand() % 5);
	}
	else {
		leave();
	}
}

void saveFriend() {
	savedFriend = true;
	cout << endl << demon << " vomits and coughs. " << demon << " approaches you, confused. You climb out of the cellar with " << demon << " it is cold and dark outside.";
	string choice = "";
	do {
		cout << "\nDo you stay or leave?: ";
		getline(cin, choice);
		choice = toCaps(choice);
	} while (choice.find("STAY") == string::npos && choice.find("LEAVE") == string::npos);
	if (choice.find("STAY") != string::npos) {
		freeze(false);
	}
	else {
		leave();
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
			<< "\nYOU DIED.\n" << endl;
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
		cout << endl << demon <<  " cuts your mouth from cheek to cheek. You fall to the ground and bleed out.\nYou die with your eyes wide open.\nYOU DIED.\n";
	}
	else if (deathCode == 4) {
		cout << endl << demon << " comes from behind and puts you in a chokehold. On the verge of choking to death, he snaps your neck, your body sliding out of his hands like a rag doll.\nYOU DIED.\n";
	}
	else if (deathCode == 5) {
		cout << endl << demon << " opens the door you were in. You are taken by suprise when " << demon << " takes you by the head and slams your head on the nightstand."
			<< "\nYour skull cracks open and " << demon << " smothers your face with a pillow...";
		cin.ignore();
		cout << "\nYour body is wrapped in a blanket and it is thrown out the the window.\nYOU DIED\n";
	}
	else if (deathCode == 6) {
		cout << endl << demon << " takes a step closer to you. You take a step back.\n You take another and another until you slip and fall into an open cellar door.\n"
			<< demon << " looks down on you and smiles as you head hits each step. You fall for minutes.";
		cin.ignore();
		cout << "You finally hit the floor. Your broken body spills blood on the concrete basement. The cellar door is closed and you are never seen again.\nYOU DIED\n";
	}
	else {
		cout << "\nYour chest begins to feel tight, you collapse on the floor as your heart struggles to pump blood through your body.\nYOU DIED\n";
	}
}