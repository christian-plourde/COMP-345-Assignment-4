COMP 345 Assignment #4 Team #4

Group Members: Christian Plourde I.D. 26572499 Jack Burns I.D. 40033754

WARNING
--------------------------------------------------------
If attempting to run this code in Visual Studio or Eclipse, you may encounter an error with the inclusion of file "dirent.h". This is because this file is not included in the C++ compiler with these IDE. To fix this with Visual Studio, dirent.h (included with this code) needs to be placed in Visual Studio's Include folder. This can typically be found in C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\Tools\MSVC\14.15.26726\include

Part 1
----------------------------------------------------------
The Dice effects observer is implemented within the Lib folder. It contains an update() function that displays
the result of the roll and who is rolling. It is precompiled along with the driver in the Driver folder in an executable called GameDriver.

Part 2
--------------------------------------------------------
A Card Observer has been implemented within the Lib folder that contains an update method that is called just before the game statistics are shown and shows all of the cards within the player's hand. 5 of the game cards have been implemented. The are found in the Deck folder. Each card derives from the card base class and contains a startBuy(), endBuy(), and Play() method. The startBuy() is called at the beginning of the buy cards method for each card in the deck, the end buy at the end of the buy cards method, and finally, the play method is called whenever that card is player. It is precompiled along with the GameDriver.

Part 3
--------------------------------------------------------
The GameDriver, which is precompiled, simulates a game of KONY. It runs the game with 2 computer players, one agressive, and one moderate, and up to 4 human players.