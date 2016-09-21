# Assignment 1

## Group creation deadline 2016/9/30 23:59:59
## Hand in deadline 2016/10/7 23:59:59

In this assignment you will be making Pac Man.  
This is a group assignment. You will make groups of 3 students (if for some reason this is not possible contact me before the group creation deadline). One of the group members must send an e-mail to me at johannes.hovland2@ntnu.no with the name of the group members by the group creation deadline.

One of the group members will have to **fork**(not clone) this repo. You will be developing on that fork.  
Remember to give Simon and me access so that we can look at what you have done.

## Required work
1. Finish the code in ```Level::createWalls()``` and ```WindowHandler::draw(ScreenObject* object)```so that walls are added to the level and can be drawn. The walls do not need to have any fancy textures. Filling an appropriate space with color will do.
2. Create a player object.
  3. Use the ```InputHandler``` to read input from **w, a, s, d** and add movement events to the evenet queue.
  4. Pop events from the event queue in the update function and use them to move Pac Man around.
  4. Implement collision detection so that Pac Man cannot pass through the walls and can pick up orbs.
  5. Load the provided sprite sheet and animate Pac Man as he moves
5. Create and display objects representing orbs/crates/fruit that can be collected by Pac Man and gives him points. (Sprites/textures optional but it must be visible.) These objects should disapear as Pac Man collects them.
6. Modify the mapfile so that it includes data about where spheres that give points are located.
5. Create a text handling class.
  6. Use the text handling class to load a font.
  7. Use the font to display a score in the top left corner of the screen as Pac Man picks up orbs.

## Restrictions
1. No drawing to screen outside of the ```WindowHandler``` (You are free to modify it as much as you want.)

## Suggestions for additional work
1. Add enemies (Colliding with the enemies resets Pac Man to the start position.)
  2. Give the enemies a simple AI.
2. Add functionality that let Pac Man exit on one side of the screen and enter on the other.
3. Add sound.
4. Add more levels and a way to switch between them.
5. Implement proper kerning in the font.
6. Etc


