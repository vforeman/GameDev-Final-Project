# To execute just call "make" from the bash in the same directory
# as the makefile

# SYNTAX:
# TARGET: DEPENDENCIES
# [TAB] SYSTEM COMMAND

# compiler for make to use
CXX = g++

# flags to pass to compiler
CXXFLAGS = -Werror -g

# libraries to include
All: Main

Main:	Main.o WindowController.o
	$(CXX) $(CXXFLAGS) -o Main Main.o WindowController.o PhysicsEngine.o LevelFactory.o GraphicsRenderer.o Geometry.o GameLogic.o Camera.o Dummy.o	InputController.o -lGL -lGLU -lSDL

Main.o: Main.cpp WindowController.o PhysicsEngine.o LevelFactory.o GraphicsRenderer.o Geometry.o GameLogic.o	Camera.o Dummy.o	InputController.o
	$(CXX) $(CXXFLAGS) -c Main.cpp

WindowController.o: WindowController.cpp
	$(CXX) $(CXXFLAGS) -c WindowController.cpp

PhysicsEngine.o: PhysicsEngine.cpp LevelFactory.h Vmath.h Geometry.h
	$(CXX) $(CXXFLAGS) -c PhysicsEngine.cpp

LevelFactory.o: LevelFactory.cpp Vmath.h Geometry.h
	$(CXX) $(CXXFLAGS) -c LevelFactory.cpp

GraphicsRenderer.o: GraphicsRenderer.cpp Vmath.h
	$(CXX) $(CXXFLAGS) -c GraphicsRenderer.cpp

Geometry.o: Geometry.cpp Vmath.h
	$(CXX) $(CXXFLAGS) -c Geometry.cpp

GameLogic.o: GameLogic.cpp  Dummy.h InputController.h WindowController.h Camera.h
	$(CXX) $(CXXFLAGS) -c GameLogic.cpp

Camera.o: Camera.cpp Vmath.h
	$(CXX) $(CXXFLAGS) -c Camera.cpp -o Camera.o

Dummy.o: Dummy.cpp
	$(CXX) $(CXXFLAGS) -c Dummy.cpp

InputController.o:	InputController.cpp	Vmath.h	Camera.h
	$(CXX) $(CXXFLAGS)	-c InputController.cpp

Weapon.o: Weapon.cpp	VMath.h	PhysicsEngine.h
	$(CXX) $(CXXFLAGS)	-c Weapon.cpp






# Call "make clean" to remove built objects from directory
# .o, objectfiles are included in .gitignore, incase you forget to clean
# before you add files to track
clean:
	rm -rf *.o Main *.gch

