#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include "../include/readFile.h"



void openIfs(std::string name, std::ifstream & ifs){
	ifs.open(name.c_str());
	
	/*While opening of the file fails, keep asking the name of the file
	and try to open it again*/
	while(ifs.fail()){
		ifs.clear();
		std::cout << "Unable to open file. Try again:" << std::endl;
		std::cin >> name;
		ifs.open(name.c_str());
	}
}
void openOfs(std::string name, std::ofstream & ofs){
	ofs.open(name.c_str());
	
	/*While opening of the file fails, keep asking the name of the file
	and try to open it again*/
	while(ofs.fail()){
		ofs.clear();
		std::cout << "Unable to open file. Try again:" << std::endl;
		std::cin >> name;
		ofs.open(name.c_str());
	}
}


void readIfs(std::ifstream &ifs, std::vector<BOARD> &matrix){
	BOARD temp_matrix;
	size_t size_m = matrix[0].size();
	while(!ifs.eof()){
    	for (int i{0}; i < size_m; ++i){
    		for(int j{0}; j < size_m; ++j){
    			ifs >> temp_matrix[i][j];
    		}
    	}
    	matrix.push_back(temp_matrix);
    }
}


/*std::vector<int> readIfs(std::ifstream &ifs){
	int num;
	std::vector<int> v;
	std::string temp_str;
	getline(ifs, temp_str);

	//While is not the end of the file, keep reading
	while(ifs >> num != "\n"){
		v.push_back(num);
	}
	return v;
}*/

void printOfs(std::ofstream &ofs, std::vector<int> v){
	//auto == std::vector<int>::iterator
	for(auto i{--v.end()}; i >= v.begin(); --i){
		ofs << *i << std::endl;
	}
}
