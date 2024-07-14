#include"Header.h"
#include <iostream>
#include <conio.h>  // für getch() und kbhit()


int main() {
	//Hier den Seed f�r Zufallszahlen
	int size;
	int rows;
	int millisecs;
	int mode;
	
	cout << "Gib mir die Size von Feld:\n";
	cin >> size;
	cout << "Gib mir die Rows vom Feld:\n";
	cin >> rows;

	World* matrix = new World(rows,size);
/*
	starty = (size-1) / 2;
	startx = (rows-1) / 2 ;
	matrix->grid[startx][starty] = 1;
	matrix->see();
*/
	matrix->setMid(matrix);




using namespace std;

/*
    char direction = ' ';
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
