CC = g++
CPPFLAGS = -std=c++11 -g
INC = -Isoil2/src/SOIL2/
LIB = -Lsoil2/lib/macosx -lsoil2-debug -lglfw -lglew -framework OpenGL \
			-framework Cocoa -framework IOKit -framework CoreFoundation -framework CoreVideo
OBJ = main.o Game.o Shader.o Texture.o Resource_Manager.o Sprite_Renderer.o
OBJ_DIR = obj
EXE = breakout

all : $(OBJ)
	$(CC) $(CPPFLAGS) $(LIB) $(INC)   \
		$(OBJ_DIR)/main.o \
		$(OBJ_DIR)/Game.o \
		$(OBJ_DIR)/Shader.o \
		$(OBJ_DIR)/Texture.o \
		$(OBJ_DIR)/Resource_Manager.o \
		$(OBJ_DIR)/Sprite_Renderer.o \
		-o $(EXE) 

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp -o $(OBJ_DIR)/main.o

Game.o : Game.hpp Game.cpp
	$(CC) $(CPPFLAGS) -c Game.cpp -o $(OBJ_DIR)/Game.o

Shader.o : Shader.hpp Shader.cpp
	$(CC) $(CPPFLAGS) -c Shader.cpp -o $(OBJ_DIR)/Shader.o

Texture.o : Texture.hpp Texture.cpp
	$(CC) $(CPPFLAGS) -c Texture.cpp -o $(OBJ_DIR)/$@

Resource_Manager.o : Resource_Manager.hpp Resource_Manager.cpp
	$(CC) $(CPPFLAGS) -c Resource_Manager.cpp -o $(OBJ_DIR)/$@

Sprite_Renderer.o : Sprite_Renderer.hpp Sprite_Renderer.cpp
	$(CC) $(CPPFLAGS) -c Sprite_Renderer.cpp -o $(OBJ_DIR)/$@

run : all
	./$(EXE)

clean : 
	rm obj/*.o

gdb : 
	$(CC) $(CPPFLAGS) -g -c main.cpp -o $(OBJ_DIR)/main.o \
	$(CC) $(CPPFLAGS) -g -c Game.cpp -o $(OBJ_DIR)/Game.o \
	$(CC) $(CPPFLAGS) -g -c Shader.cpp -o $(OBJ_DIR)/Shader.o \
	$(CC) $(CPPFLAGS) -g -c Texture.cpp -o $(OBJ_DIR)/$@ \
	$(CC) $(CPPFLAGS) -g -c Resource_Manager.cpp -o $(OBJ_DIR)/$@ \
	$(CC) $(CPPFLAGS) -g -c Sprite_Renderer.cpp -o $(OBJ_DIR)/$@ \
	$(CC) $(CPPFLAGS) $(LIB) $(INC)   \
		$(OBJ_DIR)/main.o \
		$(OBJ_DIR)/Game.o \
		$(OBJ_DIR)/Shader.o \
		$(OBJ_DIR)/Texture.o \
		$(OBJ_DIR)/Resource_Manager.o \
		$(OBJ_DIR)/Sprite_Renderer.o \
		-g -o $(EXE) 

	
