#pragma once


#include<iostream>
#include <stdlib.h>
#include<string>
#include<vector>
#include<time.h>
#include <Windows.h>

//unsere includes 
#include<random>
#include <conio.h>  // für getch() und kbhit()


using namespace std;


class World {

	
public:

	bool last_generation = false;

	//vars for stats
	int alive_count = 0;
	int died_count = 0;
	int born_count = 0;

	int lastGen_alive_count = 0;
	string generation_Historybar;


	/*Konstruktor von World
	erstellt einen Vektor grid
	zuf�llig gef�llt mit Lebenden und Toten Zellen*/
	World(int size, int rows) : rows(rows) {
		grid.resize(size, vector<int>(rows));

		// Zufallszahlengenerator initialisieren
    	random_device rd;  // Zufallsgerät für Seed
    	mt19937 gen(rd()); // Mersenne-Twister-Engine initialisieren
    	uniform_int_distribution<> dis(0, 1);


		for (int i = 0; i < size; i++)
		{
			for (int j= 0; j < rows; j++)
			{
				grid[i][j] = dis(gen);
				//cout << grid[i][j];
			}
			
		}
		
	}; 

	//Zeigt auf der Konsole die Welt an --> DONE! 
	void see() {
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < rows; j++)
			{
				if(grid[i][j] == 1){
					cout << "O ";
				}
				else if(grid[i][j] == 0){
					cout << "  ";
				}
				else if (grid[i][j] == 2) // zeigende zelle
				{
					cout << "*";
				}
				else if (grid[i][j] == 3){ //Display leere felder bei custom mode
					cout << ".";
				}
				

				if(j == rows-1){
					cout << endl;
				}
			}
			
		}
		
	};

	/*Ruft die livingNeigbours Funktion auf f�r jedes Feld.
	Berechnet ein neues Grid basierend auf den Regeln 
	und �berschreibt das alte Grid damit*/
	void update() {
		//vector<vector<int>> tempGrid = grid;
		vector<vector<int>> tempGrid;
		tempGrid.resize(grid.size(), vector<int>(rows));

		//no neighbours = dead
		//one neighbour = dead 
		//two neighbour = stay alive
		// rule for birth = neighbours needed

		
		for (int i = 0; i < grid.size() ; i++)
		{
			for (int j = 0; j < rows; j++){

				int livingNeighboursCount = livingNeigbours(i,j);

                if (grid[i][j] == 1) {
                    // Lebende Zelle
                    if (livingNeighboursCount < 2 || livingNeighboursCount > 3) {
                        tempGrid[i][j] = 0; // Stirbt
                    } else {
                        tempGrid[i][j] = 1; // Bleibt am Leben
                    }
                } else {
                    // Tote Zelle
                    if (livingNeighboursCount == 3) {
                        tempGrid[i][j] = 1; // Wird lebendig
                    } else {
                        tempGrid[i][j] = 0; // Bleibt tot
                    }
                }	

			}
		}


		

		if(grid == tempGrid){ //check if nothing happened => last generation
			last_generation = true; //es werden nur statische Endgeneration erkannt, oszillatroren nicht
		}

		//set temp datastructe now as our official grid
		grid = tempGrid;


	};

	void selectCells(World* matrix,int rows,int size)
	{
		int dirAD;
		int dirWS;
		char direction = ' ';

		dirWS = (matrix->grid.size() - 1) / 2;
		dirAD = (matrix->grid[0].size() - 1) / 2;
		system("cls");
		
		cout << "Bewegt dir in der Matrix mit WASD und setzt die Zelle ein (druck q to quit)" << endl;
		matrix->see();
		while (direction != 'c')
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
					default:
						break;
				}
			}
		}
	}
	void setMid(World* world)
	{	
		int startx = (world->grid[0].size() - 1 ) / 2 ;
		int starty = (world->grid.size() - 1 ) / 2;
		world->grid[starty][startx] = 2;
		world->see(); // delete later only debug purposes!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
	}


	//CUSTOM FUNCTION FROM US 
	void clear_grid(){ //function for the custom mode
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < rows; j++)
			{
				grid[i][j] = 0; //wipe grid
			}
			
		}
	};

	//CUSTOM FUNCTION FROM US
	void get_stats(){ //function is about seeing how many died, born, currently alive and maybe also a graph for visual
		
		alive_count = 0;
		died_count = 0;
		born_count = 0;	

		

		//count current alive ones and current died
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < rows; j++)
			{
				if(grid[i][j] == 1){
					alive_count++;
				}
				else{
					died_count++;
				}
			}
			
		}
		
		cout << "current alive: " << alive_count << "    current dead/not alive: " << died_count << "\n";  
		
		//POPULATIONBAR
		print_populationbar();


		lastGen_alive_count = alive_count; //set for next gen

		
		

	};

	

private:

	int rows;
	vector<vector<int>> grid;
	//vector<vector<int>> tempGrid;

	/*berechnet f�r ein Feld i des Vectors grid
	die Anzahl lebender Nachbarn*/
	int livingNeigbours(int index_x, int index_y){
		
		/*	
		
		X X X 			(i-1,j-1) (i-1,j) (i-1,j+1)   
		X O X    => 	(i,j-1) 	(i,j) 	(i,j+1)
		X X X  			(i+1,j-1) (i+1,j) (i+1,j+1)
		
		*/
		int count = 0;

        // Überprüfen und Zählen der lebenden Nachbarn
        if(index_x-1 >= 0 && index_y-1 >= 0 && index_x-1 < grid.size() && index_y-1 < rows) {
            if(grid[index_x-1][index_y-1] == 1) {
                count++;
            }
        }

        if(index_x-1 >= 0 && index_y >= 0 && index_x-1 < grid.size() && index_y < rows) {
            if(grid[index_x-1][index_y] == 1) {
                count++;
            }
        }

        if(index_x-1 >= 0 && index_y+1 >= 0 && index_x-1 < grid.size() && index_y+1 < rows) {
            if(grid[index_x-1][index_y+1] == 1) {
                count++;
            }
        }

        if(index_x >= 0 && index_y+1 >= 0 && index_x < grid.size() && index_y+1 < rows) {
            if(grid[index_x][index_y+1] == 1) {
                count++;
            }
        }

        if(index_x+1 >= 0 && index_y+1 >= 0 && index_x+1 < grid.size() && index_y+1 < rows) {
            if(grid[index_x+1][index_y+1] == 1) {
                count++;
            }
        }

        if(index_x+1 >= 0 && index_y >= 0 && index_x+1 < grid.size() && index_y < rows) {
            if(grid[index_x+1][index_y] == 1) {
                count++;
            }
        }

        if(index_x+1 >= 0 && index_y-1 >= 0 && index_x+1 < grid.size() && index_y-1 < rows) {
            if(grid[index_x+1][index_y-1] == 1) {
                count++;
            }
        }

        if(index_x >= 0 && index_y-1 >= 0 && index_x < grid.size() && index_y-1 < rows) {
            if(grid[index_x][index_y-1] == 1) {
                count++;
            }
        }

        return count;
    };


	void print_populationbar(){

		//declaration for ascii character backgroundcolor
		const std::string GREEN_BG = "\033[42m";  // Grün als Hintergrundfarbe
		const std::string RED_BG = "\033[41m";    // Rot als Hintergrundfarbe
		const std::string RESET = "\033[0m";      // Rücksetzung der Farben


		//check if too populatiorbar is too long long, cut if too long
		if(generation_Historybar.size() >= grid.size()){
			generation_Historybar = "";
		}

		//set color from current generation
		if (lastGen_alive_count <= alive_count) //ZUWACHS
		{
			generation_Historybar += "P"; //Plus
		}
		else 
		{
			generation_Historybar += "M"; //Minus
		}

		//Print whole Populationbar

		cout << "Population bar: \n"; 

		for (int i = 0; i < generation_Historybar.size(); i++)
		{
			if(generation_Historybar[i] == 'P'){
				cout << GREEN_BG << " " << RESET; // set color green
			}
			else{
				cout << RED_BG << " " << RESET; // set color red
			}
		}

		cout << "\n";
		

	}

};



