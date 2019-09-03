# **BattleshipGenerator**
## Authors

 - [Marco Antonio](github.com/MarcoAFC)
 - [Leonardo Nammur](github.com/Nammur)
## About the project
  This is an exercise project made for the course DIM0120 and has the objective of generating random [**Battleship**](https://en.wikipedia.org/wiki/Battleship_(puzzle)) puzzles, with varying m x n dimensions according to user input, in which several different sized boats are placed in a one-sided naval war game. The boats sizes and quantities are as follow:
  
  - Battleship, size 4 boat, 1.
  - Destroyer, size 3 boat, 2.
  - Cruiser, size 2 boat, 3.
  - Submarine, size 1 boat, 4.
  
  The objective, for the player, is to find out where the ships are spreaded in the board based on minimal information given by the program regarding to a few boats placings, such as some empty tiles, some boat tiles and the number of boat pieces in any given row or column. When the player correctly marks the position of all boats, the game is won.
   
## Usage
  To download and use this program, please clone the repository to your environment, then open the terminal in the corresponding file and use the command **Make**.\
  Afterwards bash the executable file with **./BattleON** [<*options*>] **<number_of_puzzle_tables>**, where:\
    **Facultative parameters:**\
      - --row (same results with -r, --r, -row):\
        Allows the user to set the **row** dimension of the matrix. If used, requires a number to be given representing the  
      desired dimension or the program won't run. The row dimension **must** be in the range [7,16], and any value smaller or
      higher than that will not be allowed. If not provided, defaults to 10.\
      - --col (same results with -c, --c, -col):\
       Allows the user to set the **column** dimension of the matrix. If used, requires a number to be given representing the
      desired dimension or the program won't run. The column dimension **must** be in the range [7,16], and any value smaller
      or higher than that will not be allowed. If not provided, defaults to 10.\
    **Required parameter:**\
       - Number of puzzles:\
         Allows the user to set the number of puzzles to be generated, and **must** be in the range[1,100] and any value  
        smaller or higher than that will not be allowed. Can't be ignored and the program will not run unless given.
         
## Limitations
  When generating smaller tables, specially if the number of rows and/or columns is smaller than 9, generation *may* occur slowly due to the incapacity of finding appropriate placings for the boats. The program will keep running until the suitable tables are generated. On 7x7 tables this will **most likely** take a while. If using the terminal and the program gets stuck, use Ctrl+C to finish the execution. Any table that had already been filled will be safely stored.
