## Demo Application

The demo application includes initializing the required objects to run the game server,  
adding a `Table` as a game `Map`,  and a toy `Robot` as an `Object` that can be placed on the `Map`.  

The demo application starts in the terminal and waits for the following commands:
* PLACE X,Y,F  
Puts the toy robot on the table in position X,Y and facing NORTH, SOUTH, EAST, or WEST.
* MOVE  
Moves the toy robot one unit forward in the direction it is currently facing.
* LEFT  
Rotates the toy robot 90 degrees to the left.
* RIGHT  
Rotates the toy robot 90 degrees to the right.
* REPORT  
Announces the X,Y, and F of the robot.

The origin (0,0) can be considered to be the SOUTH WEST most corner.  
The first command to the robot must be a PLACE command. After that,  
any sequence of commands may be issued, in any order, including another PLACE command.

Note: To exit the demo application, press Ctrl+C / CMD+C or type:
* QUIT  
Breaks from the terminal input loop