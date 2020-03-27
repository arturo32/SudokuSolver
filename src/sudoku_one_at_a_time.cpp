#include "../include/sudoku.h"
#include <iostream>

bool check(int** matrix, int x, int y){

	//Checking for repetitions in a collunm
	for(int i{0}; i < 9; ++i){
		if(i == x) continue;
		if(matrix[i][y] == matrix[x][y]){
			return false;
		}
	}

	//Checking for repetitions in a line
	for(int i{0}; i < 9; ++i){
		if(i == y) continue;
		if(matrix[x][i] == matrix[x][y]){
			return false;
		}
	}

	//Locating the (x,y) number in relation to the 3x3 square
	int px = (x/3)*3;
	int py = (y/3)*3;

	/*Looking for repetitions of the (x,y) number inside the 
	3x3 square*/
	for(int i{px}; i < px+3; ++i){
		for(int j{py}; j < py+3; ++j){
			if(i == x && j == y) continue;
			if(matrix[i][j] == matrix[x][y]){
				return false;
			}
		}
	}

	return true;
}


bool put_number(int** matrix, int x, int y){
	int num = 0;
	if(x == 8)
	for (int i = 0; i < 9; ++i){
		for (int j = 0; j < 9; ++j){
			for(int k= 1; k < 10; ++k){
				matrix[i][j] = k;
				if(!put_number(matrix, i, j)){
					return false; 
				}
			
			}
		}
	}
	return true;
}
