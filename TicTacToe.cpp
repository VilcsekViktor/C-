// Tic Tac Toe

// Könyvtárak importálása
#include <iostream>
#include <string>
#include <ctime>


using namespace std;

// Globális változók deklarálása
char Board[9];

// Funkciók deklarálása
void showBoard();
bool moveIsValid(int m);
int whoWon(); //0-át ad vissza ha senki sem nyert
              //1-et ha a játékos
	          //2-őt ha a computer



int
main()
{
    // random szám
    srand(time(NULL));

    // lokális változók deklarálása
    string Player_1_Name;
    string Player_2_Name;
    int Whose_Turn = 1;		// 1 means it's player 1's turn, 2 means it's player 2's turn
    int Move;			// Stores where the player wants to move
    int Total_Moves = 0;

    //Mezőkhöz értékek rendelése
    Board[9] = '9';
    Board[8] = '8';
    Board[7] = '7';
    Board[6] = '6';
    Board[5] = '5';
    Board[4] = '4';
    Board[3] = '3';
    Board[2] = '2';
    Board[1] = '1';

    // Játékos nevének bekérése
    cout << "Player 1: Please enter your name." << endl;
    cin >> Player_1_Name;

    
    cout << "Player 2: Computer." << endl;
 

    while (whoWon() == 0 && Total_Moves < 9) {
	// Ismételjen addig ameddig megfelelő input nem érkezik
	do {
	    if (Whose_Turn == 1) {
		// Tábla megjelenítése
		showBoard();

		cout << Player_1_Name << ": It's your turn." << endl;
		// Lépés bekérése
		cout << "Enter the number of the spot where you'd like to move." << endl;
		cin >> Move;

	    } else {
		// Computer random mezőt választ
		Move = rand() % 9;
	    }

	} while (moveIsValid(Move) != true);

	// 1-et ad az összes mozgáshoz
	Total_Moves++;

	// Cseréljen játékost
	switch (Whose_Turn) {
	case (1):
	  
	  Board[Move] = 'x';
	  Whose_Turn = 2;
	  break;
	case (2):
	  Board[Move] = 'o';
	  Whose_Turn = 1;
	}
    }

    // Tábla rajzolása
    showBoard();


    switch (whoWon()) {
    case 1:
	cout << "Computer nyert!" << endl;
	break;
    case 2: 
	cout << Player_1_Name << " nyert" << endl;
	break;
    default:
	cout << "Döntetlen" << endl;
	break;
    }

    system("PAUSE");
}

void
showBoard()
{
    cout << endl;
    cout << Board[7] << " | " << Board[8] << " | " << Board[9] << endl;
    cout << "--+---+--" << endl;
    cout << Board[4] << " | " << Board[5] << " | " << Board[6] << endl;
    cout << "--+---+--" << endl;
    cout << Board[1] << " | " << Board[2] << " | " << Board[3] << endl;
    cout << endl;
}

bool
moveIsValid(int m)
{
    
    return (Board[m] != 'x' && Board[m] != 'o');
}


int charToWinner(char ch)
{
    if (ch == 'x') {
	return 1;
    } else {
	return 2;
    }
}
    
int
whoWon()
{
    if (Board[7] == Board[8] && Board[8] == Board[9]) {
	
	return charToWinner(Board[0]);
    }

    if (Board[4] == Board[5] && Board[5] == Board[6]) {
	return charToWinner(Board[3]);
    }

    if (Board[1] == Board[2] && Board[2] == Board[3]) {
	return charToWinner(Board[6]);
    }

    if (Board[7] == Board[4] && Board[4] == Board[1]) {
	return charToWinner(Board[0]);
    }

    if (Board[8] == Board[5] && Board[5] == Board[2]) {
	return charToWinner(Board[1]);
    }
    if (Board[9] == Board[6] && Board[6] == Board[3]) {
	return charToWinner(Board[2]);
    }

    if (Board[7] == Board[5] && Board[5] == Board[3]) {
	return charToWinner(Board[0]);
    }

    if (Board[9] == Board[5] && Board[5] == Board[1]) {
	return charToWinner(Board[2]);
    }
    return 0;
}