#ifndef READFILE_H
#define READFILE_H

#include "sudoku.h"

void openIfs(std::string name, std::ifstream & ifs);
void openOfs(std::string name, std::ofstream & ofs);
void readIfs(std::ifstream &ifs, std::vector<BOARD> &matrix);
void printOfs(std::ofstream &ofs, std::vector<int> v);


#endif