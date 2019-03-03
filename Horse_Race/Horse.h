#include <iostream>
#include <cstdlib>
#include <ctime>
#ifndef HORSE_H
#define HORSE_H
using namespace std;

class Horse {
	private:
		string horseName;    // A string holding the horses name.
		string riderName;  // A string holding the rider’s name.
		int maxRunningDistPerSecond;   // An int that holds the maximum distance the horse could run in one second.
		int distanceTraveled; // How far the horse has gone already.
		int racesWon; // An int that determines how much races this horse and rider have won
	
	public:
		Horse(string,string);  // Constructor
		string displayHorseName();
		string displayRiderName();
		int getWins();
		int getDistanceTraveled();
		void winRace();
		void runASecond(); //  Logic to Player
		void sendToGate();   // sets distanceTraveled to 0;
		void displayHorse(int);  // will draw the game;

};

#endif
