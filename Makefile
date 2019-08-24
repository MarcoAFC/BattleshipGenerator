all: BattleON

INC = ./include
SRC = ./src
BUI = ./build
BIN = ./bin

BattleON: $(BUI)/main.o $(BUI)/posicionar.o $(BUI)/encontrarpos.o $(BUI)/boats.o $(BUI)/print.o $(BUI)/rdtsc.o 
	g++ -o BattleON $(BUI)/main.o $(BUI)/posicionar.o $(BUI)/encontrarpos.o $(BUI)/boats.o $(BUI)/print.o $(BUI)/rdtsc.o

$(BUI)/main.o: $(SRC)/main.cpp $(INC)/posicionar.h $(INC)/encontrarpos.h $(INC)/posicionar.h $(INC)/print.h $(INC)/rdtsc.h
	g++ -o $(BUI)/main.o $(SRC)/main.cpp -c -W -Wall -ansi -std=c++11


$(BUI)/posicionar.o: $(SRC)/posicionar.cpp $(INC)/posicionar.h $(INC)/print.h
	g++ -o $(BUI)/posicionar.o $(SRC)/posicionar.cpp -c -W -Wall -ansi -std=c++11

$(BUI)/encontrarpos.o: $(SRC)/encontrarpos.cpp $(INC)/encontrarpos.h $(INC)/posicionar.h $(INC)/rdtsc.h
	g++ -o $(BUI)/encontrarpos.o $(SRC)/encontrarpos.cpp -c -W -Wall -ansi -std=c++11

$(BUI)/print.o: $(SRC)/print.cpp $(INC)/print.h
	g++ -o $(BUI)/print.o $(SRC)/print.cpp -c -W -Wall -ansi -std=c++11

$(BUI)/rdtsc.o: $(SRC)/rdtsc.cpp $(INC)/rdtsc.h
	g++ -o $(BUI)/rdtsc.o $(SRC)/rdtsc.cpp -c -W -Wall -ansi -std=c++11


$(BUI)/boats.o: $(SRC)/boats.cpp $(INC)/boats.h
	g++ -o $(BUI)/boats.o $(SRC)/boats.cpp -c -W -Wall -ansi -std=c++11

