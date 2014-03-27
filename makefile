# To execute just call "make" from the bash in the same directory
# as the makefile

# SYNTAX:
# TARGET: DEPENDENCIES
# [TAB]: SYSTEM COMMAND

# This is the final executable. Last file to be compiled.
all:	main

main:	Main.o GraphicsManager.o PhysicsManager.o WindowManager.o
	g++ Main.o GraphicsManager.o PhysicsManager.o -o main

Main.o:	Main.cpp
	g++ -c Main.cpp

GraphicsManager.o:	GraphicsManager.cpp
	g++ -c GraphicsManager.cpp

PhysicsManager.o:	PhysicsManager.cpp
	g++ -c PhysicsManager.cpp

WindowManager.o:	WindowManager.cpp
	g++ -c WindowManager.cpp

# Call "make clean" to remove built objects from directory
# .o, objectfiles are included in .gitignore, incase you forget to clean
# before you add files to track
clean:	
	rm -rf *.o main

