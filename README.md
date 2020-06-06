# Suduko-Solver
9X9 Sudoku-Solver


Sudoku is a logic-based, combinatorial number-placement puzzle. The objective is to fill a 9×9 grid with digits so that each column, each row, and each of the nine 3×3 subgrids that compose the grid (also called "boxes", "blocks", or "regions") contain all of the digits from 1 to 9. The puzzle setter provides a partially completed grid, which for a well-posed puzzle has a single solution.

#suduko-puzzle
![](img/suduku-puzzle.png)  ![](img/suduku-puzzle-solution.png)  

Sudoku can be solved using #Backtracking.

I followed the following steps:

1. isSafe() that checks after assigning the current index the grid becomes unsafe or not. Keep Hashmap for a row, column and boxes. If any number has a frequency greater than 1 in the hashMap return false else return true; hashMap can be avoided by using loops.

2. A recursive function SolveSudoku(),  which takes a grid.

3. Check for any unassigned location. If present then assign a number from 1 to 9, check if assigning the number to current index makes the grid unsafe or not, if safe then recursively call the function for all safe cases from 0 to 9. if any recursive call returns true, end the loop and return true. If no recursive call returns true then return false.

4. If there is no unassigned location then return true.

>> We have also counted no of recursion call for a sudoku.

for the world's Toughest Sudoku puzzle, it took #49559 recursive calls.

![](img/toughest-suduku-puzzle.png)
