#Files to be compiled
OBJS = main.cpp WindowHandler.cpp globals.cpp InputHandler.cpp ScreenObject.cpp SpriteHandler.cpp Level.cpp

#Compiler
CC = g++

#Compiler flags
# -Wall 		Includes warnings
# -g			Include debug information in the executable
# -std=c++14	Use c++ 14
CFLAGS = -Wall -g -std=c++14

#Linker flags
# -lSDL2		Link to the SDL2 library
# -lSDL2		Link to the SDL2_image library, needed for more advanced image file types
LFLAGS = -lSDL2 -lSDL2_image

#Name of our exectuable
OBJ_NAME = packman.exe

#This is the target that compiles our executable
#Run with command: "make"
all : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LFLAGS) -o $(OBJ_NAME)

#Removes old compiled files. Usefull for running clean builds.
#Run with command: "make clean"
clean :
	rm *.o
	rm $(OBJ_NAME)