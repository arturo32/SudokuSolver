#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <array>

#include "../include/sudoku.h"


int main(void){

    std::vector<BOARD> boards;
    BOARD temp_board;

    while(!std::cin.eof()){
    	for (int i = 0; i < SIZE; ++i){
    		for(int j{0}; j < SIZE; ++j){
    			std::cin >> temp_board[i][j];
    		}
    	}
    	boards.push_back(temp_board);
    }
    
    for(int i{0}; i < boards.size()-1; ++i){
        std::cout << "Board " << i+1 << ":\n";
        print( boards[i]);
        std::cout << "Is valid? " << std::boolalpha << is_valid( boards[i] ) << std::endl;
        std::cout << "\n";
    }

    return 0;
}
