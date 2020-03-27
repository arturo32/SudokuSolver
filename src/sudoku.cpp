#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <array>

#include "../include/sudoku.h"

void print( BOARD b ){
    for(int i{0}; i < SIZE; ++i){
        for(int j{0}; j < SIZE; ++j){
            std::cout << b[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
}

bool check_row(BOARD b){

	/*Setting all elements of v as zeros. Each position in this array
	represents a number from 1 to 9, i.e., v[0] is 1, v[1] is 2*/
	short v[SIZE] = {0};


	//Checking for repetitions in a row
    for(int i{0}; i < SIZE; ++i){
        for(int j{0}; j < SIZE; ++j){

        	//Sudoku can't have zeros or negative numbers
        	if(b[i][j] <= 0 || b[i][j] > 9){
        		std::cout << "have invalid number" << std::endl;
        		return false;
        	}

        	/*Getting the value in the (i, j) position and adding one
        	to the value-1 position in the v array*/
			v[ (b[i][j])-1 ]++;

			//If a number was found more than one time
			if(v[ (b[i][j])-1 ] > 1){
				std::cout << "row: " << i << std::endl;
				return false;
			}

		}
		//Reseting the v array for the next row
		std::fill_n(v, SIZE, 0);
	}
	return true;
}

bool check_collumn(BOARD b, short c){
	/*Setting all elements of v as zeros. Each position in this array
	represents a number from 1 to 9, i.e., v[0] is 1, v[1] is 2*/
	short v[SIZE] = {0};


	//Checking for repetitions in a collumn
    for(int j{0}; j < SIZE; ++j){
        for(int i{0}; i < SIZE; ++i){

        	//Sudoku can't have zeros or negative numbers
        	if(b[i][j] <= 0 || b[i][j] > 9){
        		std::cout << "have invalid number" << std::endl;
        		return false;
        	}

        	/*Getting the value in the (i, j) position and adding one
        	to the value-1 position in the v array*/
			v[ (b[i][j])-1 ]++;

			//If a number was found more than one time
			if(v[ (b[i][j])-1 ] > 1){
				std::cout << "collumn: " << j << std::endl;
				return false;
			}

		}
		//Reseting the v array for the next row
		std::fill_n(v, SIZE, 0);
	}
	return true;
}

bool check_squares(BOARD b){

	/*Setting all elements of v as zeros. Each position in this array
	represents a number from 1 to 9, i.e., v[0] is 1, v[1] is 2*/
	short v[SIZE] = {0};

    /*Looking for repetitions of the (x,y) number inside the 
    3x3 square*/
    for(int i{0}; i < SIZE; i+= 3){
        for(int j{0}; j < SIZE; j+= 3){
    
        	for(int m{i}; m < i+3; ++m){
        		for(int n{j}; n < j+3; ++n){

        			/*Getting the value in the (i, j) position and adding one
        			to the value-1 position in the v array*/
        			v[ (b[m][n])-1 ]++;

        			//If a number was found more than one time
					if(v[ (b[m][n])-1 ] > 1){
						std::cout <<  "submatrix: " << i << ", " << j << std::endl;
						return false;
					}


        		}
        	}

        	//Reseting the v array for the next row
			std::fill_n(v, SIZE, 0);

        }
    }
    return true;
}




bool is_valid( BOARD b ){
	//Checking for repetitions in a collumn
    for(short j{0}; j < SIZE; ++j){
			if(!check_collumn(b, j)){
				return false;
			}
	}
	if(!check_row(b)){
		return false;
	}
	if(!check_squares(b)){
		return false;
	}

	return true;
       
}

