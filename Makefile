CC = g++
#INC = -I
OBJ = main.o Game.o
OBJ_DIR = obj
EXE = breakout

all : $(OBJ)
	$(CC) \
		$(OBJ_DIR)/main.o \
		$(OBJ_DIR)/Game.o \
		-o $(EXE) 

main.o : main.cpp
	$(CC) -c main.cpp -o $(OBJ_DIR)/main.o


Game.o : Game.hpp Game.cpp
	$(CC) -c Game.cpp -o $(OBJ_DIR)/Game.o

run : all
	./$(EXE)
