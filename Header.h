#pragma once


#include<iostream>
#include <stdlib.h>
#include<string>
#include<vector>
#include<time.h>
#include <Windows.h>

//unsere includes 
#include<random>



using namespace std;


class World {

public:
	vector<vector<int>> grid;
	/*Konstruktor von World
	erstellt einen Vektor grid
	zuf�llig gef�llt mit Lebenden und Toten Zellen*/
	World(int size, int rows) : rows(rows) {
		grid.resize(size, vector<int>(rows));


		// Zufallszahlengenerator initialisieren
    	random_device rd;  // Zufallsgerät für Seed
    	mt19937 gen(rd()); // Mersenne-Twister-Engine initialisieren
    	uniform_int_distribution<> dis(0, 1);

	}; 

	//Zeigt auf der Konsole die Welt an --> DONE! 
	void see() {
	
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < rows; j++)
			{
				if(grid[i][j] == 1){
					cout << "O";
				}
				else{
					cout << ".";
				}

				if(j == rows-1){
					cout << endl;
				}
			}
			
		}
		
	};
	void setMid(World* world)
	{	
		int startx = (world->grid[0].size() - 1 ) / 2 ;
		int starty = (world->grid.size() - 1 ) / 2;
		world->grid[starty][startx] = 1;
		world->see(); // delete later only debug purposes!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
	}
	/*Ruft die livingNeigbours Funktion auf f�r jedes Feld.
	Berechnet ein neues Grid basierend auf den Regeln 
	und �berschreibt das alte Grid damit*/
	void update() {
		vector<vector<int>> tempGrid = grid;

		//no neighbours = dead
		//one neighbour = dead 
		//two neighbour = stay alive
		// rule for birth = neighbours needed

		
		for (int i = 0; i < grid.size() ; i++)
		{
			for (int j = 0; j < rows; j++){
				int living = livingNeigbours(i,j);
				if (grid[i][j] == 1)
				{
					if (living < 2 || living > 3)
					{
						tempGrid[i][j] = 0;
					}
					else 
					{
						tempGrid[i][j] = 1;
					}
				}
				else 
				{
					if (living == 3)
					{
						tempGrid[i][j] = 1;
					}
					else 
					{
						tempGrid[i][j] = 0;
					}
				}

			}
		}


		//set temp datastructe now as our official grid
		grid = tempGrid;


	};

private:

	int rows;
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

};



