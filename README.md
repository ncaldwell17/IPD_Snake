# IPD_Snake


My Snake game consists of three main programs – Controller, View, and Model – inspiration taken from the original Hexapawn game that this program is built on top of because of issues I was having with ge211 when I tried to build the game out from scratch. 

## Model.h

  The Model is the most complex program out of the three and involves the game ‘rules’ and logic that run it. Model.h contains all of the constants needed for the game:
•	Screen_width
•	Screen_height
•	Cellsize
•	Enum class Direction
•	Enum class Body Part
•	Enum class Apple Type
•	Enum class Game State
•	A Snake struct to hold a type of type Body Part, coordinates, and the direction of the snake
•	An Apple struct to hold the apple_type of type Apple Type, and the coordinates of the apple

  I used the enum class to represent data more easily than simply using four or so vague ints or other data types – especially because representing variables in a vague way was problematic in both my Hexapawn and check-in for the final project. 
  I declared my structs outside of a class so I could access it easily instead of using a get function (which I don’t 100% have confidence in using). 
  The class Model contains the functions needed to run my game – namely, the constructor function, move the snake, update the game, a boolean determinant for whether or not the snake hits the edge, a boolean determinant for whether or not the snake has bitten itself (N/A because I couldn’t figure out how to extend the snake’s body), a boolean determinant for whether or not the snake head has made contact with the apple, and a function to spawn a new apple. There are also four get functions to make testing and other helper functions easier. 

## Model.cpp
  The first function Model() serves as the constructor for the game, so all of the three initial variables (the first apple, the direction of the snake’s movement, and the snake itself) get set here. The apple struct is set to type: safe, at coordinates (screen-width / 2, screen-height / 2), the direction is set to right, and the snake is constructed using a vector which would theoretically hold three of the green dots if I could figure out how to extend the body. 
	The second function move_Snake takes in a direction and keyboard input and sets the current direction as the input. It also contains four lines that prevent the snake from going backward if it’s already moving in a certain direction. 
	My three boolean functions determine:
1.	Whether or not the snake head has hit the edge – it is default set to false, unless one of the conditions below it has been met, namely:
a.	If the snake’s y coordinate is less than 0 (meaning it hit the topmost coordinate) and its current direction is up. 
b.	If the snake’s y coordinate is more than 0 (meaning it hit the bottommost coordinate) and its current direction is down. 
c.	If the snake’s x coordinate is less than 0 (meaning it hit the leftmost coordinate) and its current direction is left. 
d.	If the snake’s x coordinate is more than 0 (meaning it hit the rightmost coordinate) and its current direction is right. 
e.	If any of these conditions have been met, then the function edge returns true. 
2.	Whether or not the snake head has collided with the apple’s coordinates [[I originally had everything set to return true or false depending on the conditions, but CLion did this thing where it said the function could be simplified and it turned it into that, so I’m assuming the true false thing is implicit]]. 
a.	Basically just says if the snake_body[0]’s current position’s x is less than the apple’s coordinate’s x plus the size of the cells AND the snake’s head’s current position’s x plus the cellsize is more than the apple’s coordinate’s x AND so on for the y coordinates, the answer is true. Otherwise, it’s false. 
3.	Spawn_apple() works by declaring newtype as a new variable, setting its default to type: ‘safe’, but if the random number produced by spawning the apple is divisible by 2, it becomes an ‘unsafe’ apple. A new apple is then generated using the newtype and random screen coordinates produced by the rand command. 
4.	Bite_self() is the same collision algorithm as eat_apple(), but it was problematic because when I’d generate more than the head of the snake AND set the 


  Finally, the most important function is update. For this function – turn your attention to controller.cpp – the function on_frame() (derived from the ge211 library) allows the program to capture the seconds between each frame. The controller::on_frame() function returns nothing if the game state is game over, but triggers update if it’s in play. 
  I set two variables (change and curr_body_position) to allow them to serve multiple purposes below. The first set of if branches add one or subtract one from the snake head’s respective x and y coordinates depending on the current direction. These if branches combined with the ability of the system to capture seconds between frame shifts allows for continuous motion of the snake head. 
  My body update loop and my attempts to tell whether or not the snake has bitten itself failed – couldn’t quite get them to work properly (basically freezes the snake head and snake body in place when I try and utilize it). My hit edge works fine – it just ends the game whenever my edge function returns true. 
  The final section of the function is the if statement concerning eat_apple, where if the snake eats a safe apple, the snake’s speed adds 100 and the score adds 10 (couldn’t get the score to display). If the snake eats an unsafe apple, the snake’s speed decreases by 50, and loses 5 points. If I had more time, I’d make the poison apple disappear after a set amount of time. The program then spawns another apple using spawn_apple’s function. 

## View.h

  My view.h contains all of the constants that I need to draw the game – namely, the color of the grid squares (kind of unnecessary, but I thought they helped the player identify which row they were in), ignore the two structs right under class View, those were additions before I understood how to do continuous motion. The private variables are also just constants that I need to implement the functions in view.cpp. 

## View.cpp

  The main complicated part of view.cpp is the draw function – the creation of the tiled board that the snake and apple appear on, accomplished with a for loop that says while i (the number of tiles) and j (also the number of tiles) are less than 50, add 1 to each of them. The grid generates two different tiles based on whether or not the sum of j + i is an odd or even number. 
	The draw function’s remaining parts simply use the variables defined in view.h to display the rest of the game pieces – the snake body at the required coordinates, the right apple types at the right coordinates. These are obtained from the private sector using get statements. 
	Above that is just the constructor for View and the screen dimensions render. 

## Controller.h & Controller.cpp

  Self-explanatory. 

## Test Cases

Test Case #1 – Initialization
•	Tests to make sure all the initial variables are where they should be. 

Test Case #2 – Gameplay 
•	Tests to make sure that all the directions are working properly, AND that the user cannot reverse the snake if they try to use the opposing direction. 

Test Case #3 – Hitting Edge?
•	Tests using the update function to track seconds gone by (i.e. 3, 10) and checking to make sure that the game state updates when the snake has hit the edge. 


## Additional Missing Functionality 

1.	Snake body not increasing as the snake eats an apple. 

2.	Score not rendering in margin below. 

3.	Hexagonal Grid

4.	Tests making sure that things are functioning when the snake bites an apple, hits a wall other than the bottom, or bites itself 
