// HalloweenStory.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

string user, demon;
bool savedFriend, hasBible;

void setVars();
void start();

int main()
{
	setVars();
	start();
}

void setVars() {
	savedFriend = false;
	hasBible = false;
	cout << "This story involves a character and their friend.\n" << "What will you name the main character?: ";
	cin >> user;
	cout << "What will you name their friend?: ";
	cin >> demon;
}

void start() {
	cout << "October 31st,\n" << user << "'s class decided that a field trip to the nearest farm would be a great break from class." << endl;
	cout << "The bus stops at the front entrance. A ";
}