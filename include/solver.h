#ifndef SOLVER_H
#define SOLVER_H
	
#define EMPTY short(0)
#define SIZE 9

typedef std::array<std::array<short, SIZE>, SIZE> BOARD;

bool check(BOARD b, int x, int y);
bool solveSudoku(BOARD& board, int x, int y);
bool put_number(int** matrix, int x, int y);
void print(BOARD b);

#endif