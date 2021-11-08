#pragma once
#include "Utility.h"
#include "Board.h"
#include "Pacman.h"
#include "Ghost.h"



class Game {

public:
	void startGame();
	int getKey();
	void print_Menu();
	void Menu(Board b);
	void printInstructions();
	bool isValidkey(char key);

	void pauseGame(Board b);

};