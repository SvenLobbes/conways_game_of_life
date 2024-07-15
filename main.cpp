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

	char direction = ' ';
	char direction1 = ' ';
	
	cout << "Gib mir die Size von Feld:\n";
	cin >> size;
	cout << "Gib mir die Rows vom Feld:\n";
	cin >> rows;

	World* matrix = new World(rows,size);
	matrix->setMid(matrix);
	dirWS = (matrix->grid.size() - 1) / 2;
	dirAD = (matrix->grid[0].size() - 1) / 2;
	system("cls");
	cout << "Bewegt dir in der Matrix mit WASD und setzt die Zelle ein (druck q to quit)" << endl;
	matrix->see();
	while (direction != 'q' || direction1 != 'c')
	{
		 if (_kbhit()) { // Prüfen, ob eine Taste gedrückt wurde
            direction = _getch(); // Taste lesen
            switch (direction) {
                case 'w':
					
					if(matrix->grid[dirWS][dirAD] == 1)
					{
						matrix->grid[dirWS][dirAD] = 1;
					}
					
					else 
					{
						matrix->grid[dirWS][dirAD] = 0;
					}
					dirWS = dirWS - 1;
					if (dirWS == -1)
						{
							dirWS = rows -1;	
						} 
					matrix->grid[dirWS][dirAD] = 2;

					system("cls");
					matrix->see();
                    break;
                case 'a':
                    if(matrix->grid[dirWS][dirAD] == 1)
					{
						matrix->grid[dirWS][dirAD] = 1;
					}
					
					else 
					{
						matrix->grid[dirWS][dirAD] = 0;
					}
					dirAD = dirAD - 1;
					if (dirAD == -1)
						{
							dirAD = size - 1;	
						} 
					matrix->grid[dirWS][dirAD] = 2;

					system("cls");
					matrix->see();
                    break;
                case 's':
                   if(matrix->grid[dirWS][dirAD] == 1)
					{
						matrix->grid[dirWS][dirAD] = 1;
					}
					
					else 
					{
						matrix->grid[dirWS][dirAD] = 0;
					}
					dirWS = dirWS + 1;
					if (dirWS == rows)
						{
							dirWS = 0;	
						} 
					matrix->grid[dirWS][dirAD] = 2;

					system("cls");
					matrix->see();
                    break;
                case 'd':
                     if(matrix->grid[dirWS][dirAD] == 1)
					{
						matrix->grid[dirWS][dirAD] = 1;
					}
					
					else 
					{
						matrix->grid[dirWS][dirAD] = 0;
					}
					dirAD = dirAD + 1;
					if (dirAD == size)
						{
							dirAD = 0;	
						} 
					matrix->grid[dirWS][dirAD] = 2;

					system("cls");
					matrix->see();
                    break;
				case 'p':
					matrix->grid[dirWS][dirAD] = 1;
					system("cls");
					matrix->see();
					break;
				case 'c':
					cout << "Let the games beginn!!!!" << endl;
                case 'q':
                    cout << "Quitting" << endl;
					return 0;
                    break;
                default:
                    break;
            }
        }
		
	}
/*
	starty = (size-1) / 2;
	startx = (rows-1) / 2 ;
	matrix->grid[startx][starty] = 1;
	matrix->see();

	matrix->setMid(matrix);






    cout << "Use WASD keys to navigate (press 'q' to quit):" << endl;

    while (direction != 'q') {
        if (_kbhit()) { // Prüfen, ob eine Taste gedrückt wurde
            direction = _getch(); // Taste lesen
            switch (direction) {
                case 'w':
                    cout << "Moving Up" << endl;
                    break;
                case 'a':
                    cout << "Moving Left" << endl;
                    break;
                case 's':
                    cout << "Moving Down" << endl;
                    break;
                case 'd':
                    cout << "Moving Right" << endl;
                    break;
                case 'q':
                    cout << "Quitting" << endl;
                    break;
                default:
                    break;
            }
        }
    
}

	
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
