#include <iostream>
using namespace std;

class TicTacToe {
	private:
		char array[3][3];
		bool status;
		void checkMap();
		bool spotFill(int, int);
	public:
		TicTacToe();
		~TicTacToe(){ 
			delete array;}
		void displayMap();
		void setX(int, int);
		void setO(int, int);
		void reset();
		void winner(int);
		void winner(int, int);
		void procedure();
		bool getStatus()
			{return status;}
};

int main() {
	TicTacToe game;
	bool turn = true;
	char ch = 'y';
	int x, y;
	
	cout << "Welcome to the game of Tic-Tac-Toe." << endl;
	game.displayMap();
	do{
		if(turn)
			cout << "Player 1 choose your spot." << endl;
		else
			cout << "Player 2 choose your spot." << endl;
		cin >> x >> y;
		if(turn)
			game.setX(x - 1,y - 1);
		else
			game.setO(x - 1,y - 1);
		game.procedure();
		turn = !turn;
		if(game.getStatus()) {
			cout << "Would you like to play again?" << endl;
			cin >> ch;
			if(ch == 'y')
				game.reset();
			turn = true;
		}
	} while (ch == 'y');
}

void TicTacToe::checkMap() {
	bool full = true;
	int i = 0, j = 0;
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			if(array[i][j] == '*')
				full = false;
		}	
	}
	if(full)
		winner(0);
	
	j = 0;
	for(i = 0; i < 3; i++) {
		if(array[i][j] == array[i][j+1] == array[i][j+3])
			winner(i,j);
	}
	i = 0;
	for(j = 0; j < 3; j++) {
		if(array[i][j] == array[i+1][j] == array[i+2][j])
			winner(i,j);
	}
	if(array[i][i] == array[i+1][i+1] == array[i+2][i+2])
		winner(i,j);
	else if(array[i][j] == array[i+1][j-1] == array[i+2][j-2])
		winner(i,j);
}
bool TicTacToe::spotFill(int x, int y) {
	if(array[x][y] == '*')
		return false;
	else
		return true;
}

TicTacToe::TicTacToe() {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++)
			array[i][j] = '*';
	}
	status = false;
}
void TicTacToe::displayMap() {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++)
			cout << array[i][j] << " ";
		cout << endl;
	}
}
void TicTacToe::setX(int x, int y) {
	while(spotFill(x,y)) {
		system("cls");
		displayMap();
		cout << "That spot has already been taken. Please choose again." << endl;
		cin >> x >> y;
		x -= 1;
		y -= 1;
	}
	array[x][y] = 'X';
}
void TicTacToe::setO(int x, int y) {
	while(spotFill(x,y)){
		system("cls");
		displayMap();
		cout << "That spot has already been taken. Please choose again." << endl;
		cin >> x >> y;
		x -= 1;
		y -= 1;
	}
	array[x][y] = 'O';
}
void TicTacToe::reset() {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++)
			array[i][j] = '*';
	}
	status = false;
}
void TicTacToe::winner(int tie) {
	cout << "The board is full. There is no winner. It is a tie." << endl;
	status = true;
}
void TicTacToe::winner(int x, int y) {
	if(array[x][y] == 'X')
		cout << "Player 1 is the winner." << endl;
	else
		cout << "Player 2 is the winner." << endl;
	status = true;
}
void TicTacToe::procedure(){
	system("cls");
	displayMap();
	checkMap();
}
