	# To execute just call "make" from the bash in the same directory
# as the makefile
# To clean call "make clean"
include makefile.inc

%.o:	%.cpp
	$(CXX) $(CXXFLAGS)  -c $< -o	$(addprefix build/,$(@F))
all: Main
Main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(addprefix build/,$(OBJECTS)) $(LIBS) -o Main

# RULES
PhysicsEngine.o: PhysicsEngine.cpp Vmath.h Geometry.h
Main.o: Main.cpp WindowController.o PhysicsEngine.o Enemy.o Weapon.o LevelFactory.o GraphicsRenderer.o GameLogic.o BSP.o Overlay.o AIManager.o Level.o InputController.h WindowController.h Camera.h LevelFactory.h GraphicsRenderer.h WindowController.h
WindowController.o: WindowController.cpp PhysicsEngine.h InputController.h LevelFactory.h Util.h GraphicsRenderer.h
LevelFactory.o: LevelFactory.cpp Vmath.h Geometry.h PhysicsEngine.h BSP.h
GraphicsRenderer.o: GraphicsRenderer.cpp Vmath.h Assets.h
Geometry.o: Geometry.cpp Vmath.h
GameLogic.o: GameLogic.cpp  Dummy.h InputController.h WindowController.h Camera.h LevelFactory.h GraphicsRenderer.h
Camera.o: Camera.cpp Vmath.h
Dummy.o: Dummy.cpp
InputController.o:	InputController.cpp	Vmath.h	Camera.h
Weapon.o: Weapon.cpp	Vmath.h	PhysicsEngine.h
Enemy.o: Enemy.cpp Vmath.h PhysicsEngine.h Util.h
BSP.o: BSP.cpp Util.h
Overlay.o:	Overlay.cpp
Level.o: Level.cpp
AIManager.o: AIManager.cpp Node.h
Node.o: Node.cpp Vmath.h
Graphics.o: Graphics.cpp
# trace.o:	trace.cpp
# Syntax for adding new Rules:
# [TARGET] : [DEPENDENCIES]
# <filename>.o: <filename>.cpp <includefile1>.h <includefile2>.h





# Call "make clean" to remove built objects from directory
# .o, objectfiles are included in .gitignore, incase you forget to clean
# before you add files to track
clean:
	rm -rf *.o *.gch build/* Main

# for testing the value of  Variables
splash:
	$(ECHO) "headers: $(HEADERS)\n\n"\
	"objects: $(OBJECTS)\n\n"\
	"libs: $(LIBS)\n\n"\
	"cppfiles: $(CPPFILES)\n\n"\
	"curdir: $(CURDIR)"
