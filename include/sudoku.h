#ifndef SUDOKU_H
#define SUDOKU_H
	
#define EMPTY short(0)
#define SIZE 9

typedef std::array<std::array<short, SIZE>, SIZE> BOARD;

void print( BOARD b );
bool check_row(BOARD b);
bool check_collumn(BOARD b, short c);
bool check_squares(BOARD b);
bool is_valid( BOARD b );

#endif