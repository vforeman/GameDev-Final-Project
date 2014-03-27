#Game Design Document
##Game Overview

###Character
>The player will be a first person camera who can fire projectiles to defeat
>enemies. The character will have a health and if the player’s health is depleted
>the game is over. Also, the player will have a crosshair to indicate where the
>bullet will travel if fired. The crosshair should be rendered to the center of
>the screen.

###Environment Design
>The Level design will incorporate a dungeon like area with
>walls to prevent and obstruct movement. Enemies will spawn at random locations
>within the dungeon level. The floor and walls will be textured. The level
>obstacles will also be generated randomly to create a unique environment feel
>for each level. There will be a designated player spawn location.

##Gameplay and Mechanics
###Game Objective
>The goal of the game is to kill all
>enemies in a wave of the dungeon. Killing all enemies will advance the level,
>which will increase the difficulty through strengthening the enemies and
>**increasing the number of enemy spawns.

###User Interface
>The game will be designed to run on Linux Operating systems with
>support for the keyboard and mouse. The perspective will be first-person.  **The
>player’s arms and weapon will show on screen.

###Mechanics
>The player will lose health if he is hit by an enemy or a projectile.
>The player will die and the game will end if the player loses all his or her
>health. The player will click either mouse button to fire his or her projectile
>or Q.

###Actions
>Standard WASD and Arrow key mapping enable movement through the level.
>Mouse movement will change the first person perspective based on the change in
>mouse position.

###Physics
>Game physics will incorporate position and radius for player and NPCs.
>In addition, bullet will travel with position and velocity. Neither player nor
>NPCs can walk through walls.  **Player attacks have knockback power.

###Movement
>Player and NPCs will be able to move three-dimensionally.

###AI
>
>
>




##Story, Setting, and Character Story
>A sphere looked at your math homework wrong.
>Better head to the dungeon and teach them a lesson about proper peer reviewing
>etiquette with your blaster and projectiles. //freaking hilarious

###Art
>Enemies will be rendered as spheres **and other shapes.
>
>

###Sound and Music
>Sound and music implementation is not in the current timeline
>for the project. **sound effects based on collision. The type of the Collided
>Objects will determine the sound produced. A sound mask and be produced from the
>logical OR of the Collided Objects’ sound keys and passed to the Sound Manager.


###Most Compelling Feature
>Enemy/Obstacle Random Spawning Feels like you never play
>the same level twice.



##Development Team:
###Victor Foreman Remington Holt Ranjay Salmon


**(if time permits)

