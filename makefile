# To execute just call "make" from the bash in the same directory
# as the makefile

# SYNTAX:
# TARGET: DEPENDENCIES
# [TAB]: SYSTEM COMMAND

#include directories
LIBS = -lSDL2 -lGL -lGLU

# This is the final executable. Last file to be compiled.
all:	main

#translate obj files into executable 'main'
main:	Main.o
	g++ -g -Werror Main.o -o main $(LIBS)

SingletonPattern.o:
	g++ -c SingletonPattern.h -o SingletonPattern.o

WindowManager.o: SingletonPattern.o
	g++ -c WindowManager.h	SingletonPattern.o -o WindowManager.o

Level.o:
	g++ -c Level.h -o Level.o

Main.o: WindowManager.o
	g++ -c Main.cpp WindowManager.o $(LIBS)






# Call "make clean" to remove built objects from directory
# .o, objectfiles are included in .gitignore, incase you forget to clean
# before you add files to track
clean:
	rm -rf *.o main *.gch

