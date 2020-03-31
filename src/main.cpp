#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <array>
#include <fstream>
#include "../include/sudoku.h"
#include "../include/readFile.h"


int main(int argc, char const *argv[]){

    std::vector<BOARD> boards;
    
    //Opening file
    std::ifstream ifs;
    openIfs(argv[1], ifs);

    //Reading file
    readIfs(ifs, boards);

    
    for(int i{0}; i < boards.size()-1; ++i){
        std::cout << "Board " << i+1 << ":\n";
        print( boards[i]);
        std::cout << "Is valid? " << std::boolalpha << is_valid( boards[i] ) << std::endl;
        std::cout << "\n";
    }

    return 0;
}
