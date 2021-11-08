#include "Board.h"

void Board::initBoardToStart(Pacman& p, Ghost g1, Ghost g2) {
	// gets the board and initializing it with walls and Breadcrums

	setWalls();
	setBreadcrumbs();
	setPacman(p);
	setGhosts(g1, g2);
}
void Board::setGhosts(Ghost g1, Ghost g2) {

	int x1 = g1.getPoint().getPointX();
	int y1 = g1.getPoint().getPointY();
	int x2 = g2.getPoint().getPointX();
	int y2 = g2.getPoint().getPointY();

	board[x1][y1] = g1.getSign();
	board[x2][y2] = g2.getSign();

}
void Board::setPacman(Pacman& p) {

	int x = p.getPoint().getPointX();
	int y = p.getPoint().getPointY();

	board[x][y] = p.getSign();
}
void Board::setBreadcrumbs() {

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (board[i][j] != WALL)
				board[i][j] = BREADCRUMB;
		}

	}
}

void Board::setWalls() {
	for (int i = 0; i < COLS; i++)	//first row of walls.
		board[0][i] = WALL;
	cout << endl;
	for (int row = 1; row < ROWS - 1; row++)	// for every row
	{
		board[row][0] = WALL;

		for (int spaces = 1; spaces < COLS - 1; spaces++)
			board[row][spaces] = BLANK;

		board[row][COLS - 1] = WALL;
		cout << endl;

	}
	for (int k = 0; k < COLS; k++)	//last row of walls.
		board[ROWS - 1][k] = WALL;
	cout << endl;
	for (int k = 40; k < 70; k++)	//wall #1
		board[20][k] = WALL;
	cout << endl;
	for (int k = 10; k < 40; k++)	//wall #2
		board[5][k] = WALL;
	cout << endl;
	for (int k = 10; k < 15; k++)	//wall #3
		board[k][40] = WALL;
	cout << endl;

}
void Board::printBoard()const {
	// gets the board and printing it on the screen

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << board[i][j];
		}
		cout << endl;

	}
}
// function definition -- requires windows.h
void Board::gotoxy(int y, int x)
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	cout.flush();
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}
// function definition -- requires process.h
void Board::clrscr()
{
	system("cls");
}
void Board::updateBoard(int x, int y, char ch) {

	board[x][y] = ch;
	gotoxy(x, y);
	cout << board[x][y];
}
char Board::getPointofBoard(int row, int col) {
	return board[row][col];
}
