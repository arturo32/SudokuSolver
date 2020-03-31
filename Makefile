
#The command "make" will call the targets mkobjects and main.
all: mkobjects main

# mkobjects creates the directory objects. -p is a flag to make
# it work even if the directory already exists.
mkobjects: 
	mkdir -p objects

# main needs the targets readFile and sudoku and the file
# main.cpp to work. It then compiles everything and creates
# the executable sudoku in the build directory.
main: readFile sudoku src/main.cpp
		g++ src/main.cpp objects/*.o -o build/sudoku

readFile: src/readFile.cpp
		g++ -c src/readFile.cpp -o objects/readFile.o

sudoku: src/sudoku.cpp
		g++ -c src/sudoku.cpp -o objects/sudoku.o


# The command "make clean" removes the objects directory and
# the executable file sudoku
clean: 
		rm -rf objects
		rm build/sudoku


