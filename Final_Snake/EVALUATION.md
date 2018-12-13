Our program involved three main components - the controller, the model, and the view, each of which were combined to create the main graphic and the user’s interaction with said graphic. 



The first challenge was simply creating each of the components. We were able to code the game’s procedure using four main function families - grid, movement, spaces, and mouse-events. Our grid functions coded which type of pawn is contained within a single square-space (paired with draw functions that displayed the type of object and several additional attributes). Our space functions determine whether or not a targeted square-space is a ‘good square’ through a series of booleans. Our mouse-event took elements from the grid functions to determine which square coordinates were being selected  Using the results from both the grid, mouse, and the space functions, our movement functions switch the images attributed to each type of square to facilitate a move. 



The second challenge was adding additional functionality to the board - namely 1) adding margins to allow for additional graphics, 2) an indication of which players’ turn it was, and 3) a game-over notification. Adding margin functionality in the view on all sides of the screen proved difficult, so we focused on only including it on the top and bottom of the screen. 



The final challenge was adding extra dimensions to the game board (wanting to play it on a nXn board instead of just a 3X3 board). 



Our tests measured the correctness through:

Making sure that the game renders properly.

Making sure that the mouse and grid functions were interacting properly (i.e., when we clicked, it was returning the proper coordinates)

Making sure that the right image was being displayed at the right place (i.e., when generated, are the pieces where they should be?) 

Making sure all the boolean conditions are met

Is it a good square?

Did we click on a square that’s in front of a pawn?

Did it return True, like it should have?

Is there an opposing piece that would allow us to move diagonally?

Did it return True, like it should have?

Is it a bad square?

Did we click on a square that’s behind the pawn? 

Did it return false, like it should have?

Did we click on a square that wasn’t directly in front of the pawn?

Did it return false, like it should have?





Interesting/Weird Things that happened:

Our board flipped on us for no reason. Didn’t impact the functionality after we re-coded some things, but we don’t really know what happened. 

For a while, we couldn’t figure out why the game would stop after we made the first turn, and realized that we hadn’t coded in a function to either 1) end the game, and 2) flip turns. 

Figuring out how to include text within the program was a bit frustrating. 

After we played the game a few times, we realized that there was a possibility of getting a tied-game because you could arrange the pawns so that neither player could win. We added an extra condition to the update_winner_and_turn function on Line 50 of model.cpp that gives ‘You Win!’ to the opposite player of the last one who went. 

Solution: Our is_good_spot function always checked the color of what turn it was in our program, so when we were trying to test the white pawns when it was black’s turn, the program didn’t register the turn changing. To fix this, we changed the turn and more_moves and before returning the result, we changed it back. 