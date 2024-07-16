#include"Header.h"

void display_menu(){
	cout << "|-------------------------------------------------------------|\n";
	cout << "|                      Conway's Game of Life                  |\n";
	cout << "|                                                             |\n";
	cout << "| Enter s to start automated Simulation                       |\n";
	cout << "| Enter c to start custom Simulation                          |\n";
	cout << "| Enter q to quit                                             |\n";
	cout << "|                                                             |\n";
	cout << "|                         Software by                         |\n";
	cout << "|           Tommaso Rubini, Andre SURNAME, Sven Lobbes        |\n";
	cout << "|                        IT For Engineers                     |\n";
	cout << "|-------------------------------------------------------------|\n";

}

int main() {
	//Hier den Seed f�r Zufallszahlen
	int size;
	int rows;
	int millisecs;

	char input;

	display_menu();
	cin >> input;

	if(input == 's' || input == 'c'){ //AUTOMATED SIMULATION (RANDOM)

		//Abfrage der Größen benutzerdefiniert -> evtl. später input abfangen
		cout << "Gib mir die Size von Feld:\n";
		cin >> size;
		cout << "Gib mir die Rows vom Feld:\n";
		cin >> rows;
		cout << "Gib mir die Intervallzeiten in Sekunden:\n";
		cin >> millisecs; 
		millisecs = millisecs * 1000; //umrechnung in millisecs for Sleep()

		//Erstellt eine Instanz der Klasse Welt
		World* grid = new World(size, rows);

		if (input == 'c')
		{
			//in the custom simulation case, we have to wipe the grid
			//and let the user pick the figures



			//wipe grid
			grid->clear_grid();

			//INSERT TOMMASO PROCEDURE for selecting own cells
			grid->setMid(grid);
			grid->selectCells(grid,rows,size);


		}
		


		while (true) {

			//zeigt die Welt an
			grid->see();
			grid->get_stats(); // custom function by sven
		

			//updatet die Welt
			grid->update();
		
			if(grid->last_generation){
				
				//grid->get_stats();
				cout << "Simulation beendet, das ist die letzte Generation:\n";

				break;
			}

			//wartet 2 Sekunden
			Sleep(millisecs);
		
			//L�scht die alte Konsolenanzeige
			system("cls");
		    
		}
	}
	else if (input == 'q'){
		return 0; //user wanted to close program
	}

	


	return 0; 
	
}
