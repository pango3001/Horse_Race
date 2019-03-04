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
	unsigned seed = time(0);
	srand(seed);
	opener();
	int size = numOfRacers();
	Horse ** horse = new Horse*[size];
	getRacers(horse, size);
	int races = 0;
	int fastest = 0;
	int goal;
	string g, cont;
	bool play_again = true;
	while (play_again) {
		
		for (int i = 0; i < size; i++)
			horse[i]->sendToGate();
		bool end_loop = false;
		while (!end_loop) {
			cout << "Please enter the distance of the race: ";
			getline(cin, g);
			goal = stoi(g);
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
					for (int j = 0; j < size; j++) {
						if (horse[j]->getDistanceTraveled() > horse[fastest]->getDistanceTraveled())
							fastest = j;
						else if (horse[j]->getDistanceTraveled() == horse[fastest]->getDistanceTraveled()) {
							int coinFlip = (rand() % 2);
							if (coinFlip == 1)
								fastest = j;
						}
					}
					finish = true;
				}
			}
			//system("cls");
			
			bool end_loop = false;
			while (!end_loop) {
				cout << "Are you ready for the next second(y/n)?: ";
				getline(cin, cont);
				//tolower(cont);
				if (cont == "y")
					end_loop = true;
				else if (cont == "n"){
					end_loop = true;
					finish = true;
					}
				else
					cout << "You're only choices are y and n" << endl;
			}
			

		}
		if(cont == "y")
			races += 1;
			horse[fastest]->winRace();
		for (int i = 0; i < size; i++) {
			cout << horse[i]->displayHorseName() << " has won " <<
			horse[i]->getWins() << "/" << races << " races." << endl;
		}
		end_loop = false;
		while (!end_loop) {
			cout << "Would you like to have another race (y/n)?: ";
			getline(cin, cont);
			//tolower(cont);
			if (cont == "y")
				end_loop = true;
			else if (cont == "n") {
				end_loop = true;
				play_again = false;
			}
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
	cout << "                            _(\\_/)" << endl;
	cout << "                          ,((((^`\\" << endl;
	cout << "                         ((((  (o \\" << endl;
	cout << "                       ,((((( ,    \\" << endl;
	cout << "   ,,,_              ,((((( /._  ,`,\\" << endl;
	cout << "  (((( \\ ,...       ,((((   |    `-.-'" << endl;
	cout << "  )))  ;'    `\"'\"'""((((     (" << endl;
	cout << " (((  /             (((      \\" << endl;
	cout << " ))  |                        |" << endl;
	cout << " ((  |        .       '       |" << endl;
	cout << " ))  (     _ '      `t     ,.')" << endl;
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
