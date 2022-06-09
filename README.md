
# Backgammon Game (Classic Backgammon(known as Erkek Tavlası in Turkish) Programming
You will create and maintain 2 files, one for Backgammon table (name must be Table.dat)(figure 2), the second table
is for Dice history and play log (the example file is like in Figure 1).

* 6
* 4
* X 2 3
* Y 6 6
* X 4 3
* .....



The starting Table.dat is like below:
Player X’s Side (Player X’s play direction is clockwise)

<p align="center">
  
  <img src="https://github.com/zeynepbetulcelik/backgammongame/blob/master/screenshots/backgammon.PNG">
</p>



Player Y’s Side (Player Y’s play direction is counter-clockwise)
E3 and F3 is the container of current dice throw
1)The starting state must be written into the file.
2) Throw of one dice each side to determine the first turn. (You may generate a random number independently for
each dice between 1 and 6 integer only)(Dice no1 is for player X, Dice no2 is for player Y. The higher side will roll
double dice to play first.
3)For example the player X won the dice roll and throw 3-1(Dice no1=3, Dice no2:1) only the player enters the source
slot, player enters E1 and G1 so computer change the E1 to “2X”, H1 to “X” (for dice 1)and computer changes the G1
to “4X” and H1 to “2X”. ,(if the dices are rolled and a double dice came like 1-1, 2-2....6-6. This dice will be played as 4
times the single dice- 4-4 means 4 times 4)
So the new Table.dat will be like below:
Player X’s Side (Player X’s play direction is clockwise)


<p align="center">
  
  <img src="https://github.com/zeynepbetulcelik/backgammongame/blob/master/screenshots/backgammon2.PNG">
</p>


And the turn will be Y’s and new dices roll.
If some player’s flake is broken by the other player, the file slot E3 is for player X and H3 is for player Y. For example
Player X has one broken and Y has 2 broken, E3 will be “X” and H3 will be “2Y”
4) The player who can pass all his/her flakes can start to pick the flakes up, whoever pick all flakes up win the
game.(When picking up you don’t need to store the picked-up flakes, only erase it from the related slot )
5) I3 will save who has the turn. (X or Y) Before each turn, turn holder can end the game for future play. Engage a
keyboard shortcut to end the game for future play and your game will save automatically the status of the game for
future play. Next time you will ask to user if he want to play the old game, if yes the game will load the old game and
continue the playback.
