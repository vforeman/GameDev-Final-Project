Technical Design Document

Overview Timeline
Player and Movement (4/1)
Artificial Intelligence (4/8)
Physics and Collision   (4/15)
Testing and Optimization  (4/24)


Development Team
Victor Foreman
Remington Holt
Ranjay Salmon
    Physics


Code Format:
Single tab
Block bracketing
Constants: MYCONSTANT
functions - 1st letter lowercase
Ex: doSomething();
      do();
Ex:
variables
    ex:    _variable
classes - 1st letter Uppercase
class
    class MyClass
    {
        public:
            _members;
            _members;
             methods();
            methods();
        private:
            _members;
            _members;
            methods();
            methods();
    };

Class Features

Core namespace Features:
Maintain global classes and structs
Utilize ‘extern’ modifier when feasible 

WindowManager namespace Features:
Open/Close window
exit calls from other modules will be to Window Class
Resize Window 
Neglible if we just work with a set size window for now

GraphicManager namespace Features:
Render Static and Dynamic GameObjects
Calling Render Component of GameObjects





Development Environment
Development Hardware
    Windows Computer running Linux OS

Development Software
Text Editors
GNU C compiler

Version control: 
GitHub

Libraries
Simple DirectMedia Layer C++
Low level access to window, sound, and input

Application Programming Interfaces (APIs)
OpenGL Graphics Library
Renders 2D and 3D graphics


Game Mechanics
Main Technical Requirements
Architecture

Graphics
    OpenGL renders graphics
Graphics will be handled by the Singleton GraphicsManager class. GraphicsManager will take a GraphicsObject derived class and draw it to the screen utilizing OpenGL commands.


Artificial Intelligence
A* Pathfinding
Proximity Alerts
State based: Patrol, Attack, Search and Destroy

Enemy objects can inherit basic NPC functionality such as patrol and search from a Base class NPC. The Enemy will be receive a proximity alert from the player’s position, and utilize A* to map a path if the proximity indicates the player is a certain distance away but less than a bounded range. The bounded range will serve as the tether location for establishing the Enemy’s patrol region. Otherwise if the player is close enough or “visible” to the enemy the Enemy will fire his blaster using a method in his class structure.

Physics
Bullet Physics
Jump
First Person Camera Collisions
Sphere-Sphere Collisions
Swept Sphere Collisions

The PhysicsManager Singleton class will calculate physics for collisions. Therefore, the PhysicsManger will determine if a collision occurs by taking two game objects comparing the vector positions utilizing a sphere-sphere collision for slow moving objects and swept sphere collisions for quick moving game objects. Furthermore, the PhysicsManager will also have a method for resolving the collisions in an appealing method.

Game Objects and Logic

User Interface
Input Handler
Keyboard
Mouse

The game will be primarily be controlled utilizing a mouse to rotate the camera utilizing a camera class, which will rotate based on the change in the mouse’s position relative to its a center position. Action command, like jump and fire, will be handled by keyUp and keyDown states which can be delegated to the InputHandler class. The InputHandler class will be modelled after the Singleton design pattern.


