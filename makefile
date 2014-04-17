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
PhysicsEngine.o: PhysicsEngine.cpp Vmath.h Geometry.h Graphics.h
Main.o: Main.cpp WindowController.o PhysicsEngine.o Enemy.o Weapon.o GraphicsRenderer.o GameLogic.o BSP.o Overlay.o AIManager.o InputController.h WindowController.h Camera.h GraphicsRenderer.h WindowController.h
WindowController.o: WindowController.cpp PhysicsEngine.h InputController.h Util.h GraphicsRenderer.h
GraphicsRenderer.o: GraphicsRenderer.cpp Vmath.h Assets.h Geometry.h Overlay.h Util.h Graphics.h Enemy.h
Geometry.o: Geometry.cpp Vmath.h
GameLogic.o: GameLogic.cpp InputController.h WindowController.h Camera.h GraphicsRenderer.h Enemy.h Player.h Weapon.h
Camera.o: Camera.cpp Vmath.h
InputController.o:	InputController.cpp	Vmath.h	Camera.h Weapon.h
Weapon.o: Weapon.cpp	Vmath.h	PhysicsEngine.h
Enemy.o: Enemy.cpp Vmath.h PhysicsEngine.h Util.h Graphics.h Weapon.h
BSP.o: BSP.cpp Util.h
Overlay.o:	Overlay.cpp Vmath.h levels.h Assets.h Util.h
AIManager.o: AIManager.cpp Node.h
Node.o: Node.cpp Vmath.h
Graphics.o: Graphics.cpp

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
