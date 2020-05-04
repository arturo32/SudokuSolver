#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <array>
#include <math.h> 
#include "../include/solver.h"



bool check(BOARD matrix, int x, int y){


	//Checking for repetitions in a collunm
	for(int i{0}; i < SIZE; ++i){
		if(i == x) continue;
		if(matrix[i][y] == matrix[x][y]){
			return false;
		}
	}

	//Checking for repetitions in a row
	for(int i{0}; i < SIZE; ++i){
		if(i == y) continue;
		if(matrix[x][i] == matrix[x][y]){
			return false;
		}
	}

	int smallSIZE = sqrt(SIZE);

	//Locating the (x,y) number in relation to the 3x3 square
	int px = (x/smallSIZE) * smallSIZE;
	int py = (y/smallSIZE) * smallSIZE;

	/*Looking for repetitions of the (x,y) number inside the 
	3x3 square*/
	for(int i{px}; i < px+smallSIZE; ++i){
		for(int j{py}; j < py+smallSIZE; ++j){
			if(i == x && j == y) continue;
			if(matrix[i][j] == matrix[x][y]){
				return false;
			}
		}
	}

	return true;
}


//Function that solves the sudoku
bool solveSudoku(BOARD& board, int x, int y){
    
    //The next x and y of the next call of the function
    int nextX, nextY;

    /*If the end of the column was not reached, we keep in the
    same column and advance to the next row*/
    if(x < SIZE-1){
        nextX = x+1;
        nextY = y;          
    }
    /*If the end of the column was reached and we are not 
    beyond the number of columns, we advance to next column
    and reset the row number*/
    else{
        if(y <= SIZE-1){
            nextY = y+1;
            nextX = 0;
        }

        /*If we are beyond the number of columns, i.e., the
        end of the sudoku was reached, true is returned*/
        else{
            return true;
        }
    }

    /*If the position (x, y) already have a fixed number in
    place, the function is called to the next position (and
    its return value is returned)*/
    if(board[x][y] != 0){

        return solveSudoku(board, nextX, nextY);       
    }

    /*Test for each number from 1 to 9 if it is valid
    following the rules of sudoku for the current
    position (x, y)*/
    for(int i = 1; i <= SIZE; ++i){
        
        //Putting number in the board
        board[x][y] = i;

        /*If the number is valid, the function for the next
        place is called and if this return true, true is also
        returned from this function.If neither the number is
        valid nor the function return true, the loop continue
        for the next iteration*/
        if(check(board, x, y)){
            if(solveSudoku(board, nextX, nextY)){
                return true;
            }
        }     
    }

    /*If all iterations of the for loop above didn't work
    then the current place is set to zero and false is 
    returned*/
    board[x][y] = 0;
    return false;
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


void print( BOARD b ){
    for(int i{0}; i < SIZE; ++i){
        for(int j{0}; j < SIZE; ++j){
            std::cout << b[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
}