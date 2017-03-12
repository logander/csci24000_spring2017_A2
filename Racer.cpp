// Honor Pledge: I pledge that I have neither given nor received any help on this assignment.

#include <iostream>
#include <stdlib.h>
#include <ctime>
#define RACE_LENGTH 50
void advanceRacerA(int* ptrRacerA);
void advanceRacerB(int* ptrRacerB);
void printPosition(int* ptrRacerA, int* ptrRacerB);

//Creating the function for the advancing of RacerA
void advanceRacerA(int* ptrRacerA) {
	// This will get the random obstacle chosen
	int N;
	N = rand() % 10 + 1;
	// Run obstacle
	if (N <= 3) {
		*ptrRacerA += 4; //Gain 4 spaces
	}
	//Sprint obstacle
	else if (N == 4) {
		*ptrRacerA += 5; //Gain 5 spaces
	}
	//Fall in Mud obstacle
	else if (N <= 7 && N >= 5) {
		*ptrRacerA -= 2; //Lose 2 spaces
	}
	//Fall off Rope obstacle
	else if (N <= 9 && N >= 8) {
		*ptrRacerA -= 3; //Lose 3 spaces
	} 
	//Fall off money bars obstacle
	else {
		*ptrRacerA -= 4; //Lose 4 spaces		
	}
	//This last one is for if he falls behind the start
	if (*ptrRacerA <= 0)
		*ptrRacerA = 1; //Sets you back to 1 if you go negative
}
void advanceRacerB(int* ptrRacerB) {
		// This will get the random obstacle chosen
	int N;
	N = rand() % 10 + 1;
	// Run obstacle
	if (N <= 4) {
		*ptrRacerB += 5; //Gain 5 spaces
	}
	//Sprint obstacle
	else if (N == 4) {
		*ptrRacerB += 6; //Gain 6 spaces
	}
	//Fall in Mud obstacle
	else if (N <= 7 && N >= 6) {
		*ptrRacerB -= 1; //Lose 1 spaces
	}
	//Fall off Rope obstacle
	else if (N <= 9 && N >= 8) {
		*ptrRacerB -= 2; //Lose 2 spaces
	} 
	//Fall off money bars obstacle
	else {
		*ptrRacerB -= 4; //Lose 4 spaces		
	}
	//This last one is for if he falls behind the start
	if (*ptrRacerB <= 0)
		*ptrRacerB = 1; //Sets you to 1 if you go negative
}
void printPosition(int* ptrRacerA, int* ptrRacerB) {
	int i;
	if (*ptrRacerA == *ptrRacerB) {
		--*ptrRacerA;
	}
	for (i = 1; i <= 50; i++) {
		if (i == *ptrRacerA) {
			std :: cout << "A";
		}
		else if (i == *ptrRacerB) {
			std :: cout << "B";
		}
		else {
			std :: cout << " ";
		}
	}
	std :: cout << "|\n";
}
int main() {
	int Player = 1, Champion = 1 ;     
	std::cout << "Welcome to Logan's amazing spartan race.\n";
	std::cout << "Ready...\n";
	std::cout << "Set...\n";
	std::cout << "GO!!!!\n";

	srand(time(NULL));      
	std::cout << "S\n";	
	do {                    
		advanceRacerA(&Player);
		advanceRacerB(&Champion);
		printPosition(&Player, &Champion);
	//These last two conditions will print if you won or lost based on who reached 50 first.
	} while (Player < 49 && Champion < 49); {
		if (Player > Champion) {             
			std::cout << "You defeated the mighty spartan champion (AKA your friend), congratulatuons!\n";
		}
		else if (Champion > Player) {        
			std::cout << "Your friend, the mighty spartan champion beat you by a mile, you gotta go train!\n";
		}
	}
	return 0;
}