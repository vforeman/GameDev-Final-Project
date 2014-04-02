# To execute just call "make" from the bash in the same directory
# as the makefile

# SYNTAX:
# TARGET: DEPENDENCIES
# [TAB] SYSTEM COMMAND

# compiler for make to use
CXX = g++

# flags to pass to compiler
CXXFLAGS = -Wall -g

# libraries to include


Main:	Main.o WindowController.o
	$(CXX) $(CXXFLAGS) -o Main Main.o WindowController.o PhysicsEngine.o LevelFactory.o GraphicsRenderer.o

Main.o: Main.cpp WindowController.h PhysicsEngine.h LevelFactory.h GraphicsRenderer.h Util.h
	$(CXX) $(CXXFLAGS) -c Main.cpp

WindowController.o: WindowController.h
	$(CXX) $(CXXFLAGS) -c WindowController.cpp

PhysicsEngine.o: PhysicsEngine.h Vmath.h
	$(CXX) $(CXXFLAGS) -c PhysicsEngine.cpp

LevelFactory.o: LevelFactory.h Vmath.h
	$(CXX) $(CXXFLAGS) -c LevelFactory.cpp

GraphicsRenderer.o: GraphicsRenderer.h Vmath.h
	$(CXX) $(CXXFLAGS) -c GraphicsRenderer.cpp



# Call "make clean" to remove built objects from directory
# .o, objectfiles are included in .gitignore, incase you forget to clean
# before you add files to track
clean:
	rm -rf *.o Main *.gch

