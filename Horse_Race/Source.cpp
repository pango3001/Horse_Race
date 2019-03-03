#include "Horse.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
void opener();
int numOfRacers();
void getRacers(Horse **racers, int size);

int main() {
	opener();
	int size = numOfRacers();
	Horse ** horse = new Horse*[size];
	getRacers(horse, size);
	int races = 0;
	int goal;
	bool play_again = true;
	while (play_again) {
		races += 1;
		for (int i = 0; i < size; i++)
			horse[i]->sendToGate();
		bool end_loop = false;
		while (!end_loop) {
			cout << "Please enter the distance of the race: ";
			cin >> goal;
			if (goal >= 100)
				end_loop = true;
			else
				cout << "Please enter a distance over 100." << endl;
		}
		cout << "Start!" << endl;
		bool finish = false;
		while(!finish){
			for (int i = 0; i < size; i++) {
				horse[i]->displayHorse(goal);
				horse[i]->runASecond();
				cout << horse[i]->displayHorseName() << " ridden by " << horse[i]->displayRiderName() << endl;
			}
			for (int i = 0; i < size; i++) {
				if (horse[i]->getDistanceTraveled() >= goal) {
					horse[i]->winRace();
					finish = true;
				}
			}
			system("cls");
		}
		for (int i = 0; i < size; i++) {
			cout << horse[i]->displayHorseName() << " has won " <<
			horse[i]->getWins() << "/" << races << " races." << endl;
		}
	}

	delete [] horse;
	return 0;
}

int numOfRacers() {
	string num;
	int number;
	bool end_loop = false;
	while (!end_loop) {
		cout << "How many horses are in the race: ";
		getline(cin, num);
		number = stoi(num);
		if (number >= 2)
			end_loop = true;
		else
			cout << "It takes at least 2 horses to have a race!" << endl;
	}
	return number;
}

void getRacers(Horse **racers, int size) {
	
	Horse ** horse = new Horse*[size];
	for (int i = 0; i < size; i++) {
		string horsen, ridern;
		cout << "Horse " << i+1 <<" name: ";
		getline(cin, horsen);
		cout << "Rider " << i + 1 << " name: ";
		getline(cin, ridern);
		horse[i] = new Horse(horsen, ridern);
		racers[i] = horse[i];
	}	
}

void opener() {
	cout << "  Welcome to the Horse races!" << endl;
	cout << "                            _(\_/)" << endl;
	cout << "                          ,((((^`\\" << endl;
	cout << "                         ((((  (o \\" << endl;
	cout << "                       ,((((( ,    \\" << endl;
	cout << "   ,,,_              ,((((( /._  ,`,\\" << endl;
	cout << "  ((((\\\ ,...       ,((((   |    `-.-'" << endl;
	cout << "  )))  ;'    `\"'\"'""((((     (" << endl;
	cout << " (((  /             (((      \\" << endl;
	cout << " ))  |                        |" << endl;
	cout << " ((  |        .       '       |" << endl;
	cout << " ))  \     _ '      `t     ,.')" << endl;
	cout << " (   |   y;- -,-\"\"'\"-.\\   \\/" << endl;
	cout << "  )  / ./  )  )        `\\  \\" << endl;
	cout << "    /  /   ( (           / /'" << endl;
	cout << "    | |    \\\\          //'|" << endl;
	cout << "    | |     \\\\       _//'||" << endl;
	cout << "````||```````))`````|_/``||```````````" << endl;
	cout << "    \\_\\     |_/          ||" << endl;
	cout << "    `'\"                  \\_\\" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

}
