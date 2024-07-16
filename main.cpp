#include"Header.h"
#include <iostream>
#include <conio.h>  // für getch() und kbhit()
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
using namespace std;


int main() {
	//Hier den Seed f�r Zufallszahlen
	int size;
	int rows;
	int millisecs;
	int mode;
	int dirAD;
	int dirWS;


	char direction1 = ' ';
	
	cout << "Gib mir die Size von Feld:\n";
	cin >> size;
	cout << "Gib mir die Rows vom Feld:\n";
	cin >> rows;

	World* matrix = new World(rows,size);
	matrix->setMid(matrix);
	matrix->selectCells(matrix,rows,size);
	matrix->update();
	/*
  

	
	cout << "Gib mir die Intervallzeiten in Sekunden:\n";
	cin >> millisecs; 
	cout << "Debug Mode? 0 = No und 1 = yes\n";
	cin >> mode;
	millisecs = millisecs * 1000; //umrechnung in millisecs for Sleep()

	//Erstellt eine Instanz der Klasse Welt
	World* grid = new World(size, rows);


	while (true) {

		//zeigt die Welt an
		grid->see();

		//updatet die Welt
		grid->update();

		//wartet 2 Sekunden
		Sleep(millisecs);
		

		//added custom mode
		if(mode == 0){
			//L�scht die alte Konsolenanzeige
			system("cls");
		}
		else if (mode == 1)
		{
			cout << "                  ";
			cout << endl; 
		}
		
	
		


	}
	
	*/
}
