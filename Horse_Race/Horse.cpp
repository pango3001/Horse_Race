#include "Horse.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>


Horse::Horse(string horse, string rider){
	unsigned seed = time(0);
	srand(seed);
	maxRunningDistPerSecond = ((rand() % 100) + 1);
	distanceTraveled = 0;
	racesWon = 0;
	horseName = horse;   
	riderName = rider;
}

string Horse::displayHorseName() {
	return horseName;
}

string Horse::displayRiderName() {
	return riderName;
}

int Horse::getDistanceTraveled() {
	return distanceTraveled;
}

int Horse::getWins() {
	return racesWon;
}

void Horse::winRace() {
	racesWon += 1;
}

void Horse::runASecond() {
	distanceTraveled += rand() % (maxRunningDistPerSecond + 1);
}

void Horse::sendToGate() {
	distanceTraveled = 0;
}

void Horse::displayHorse(int goalLength) {
	int goalScaled = 50;
	int distanceTScaled = (distanceTraveled * 50) / goalLength;
	cout << "|";
	for (int i = 0; i < goalScaled; i++) {
		if (distanceTScaled == i)
			cout << ">";
		else if (distanceTScaled < i)
			cout << " ";
		else if (distanceTScaled > i)
			cout << "-";
	}
	cout << "|";
}