// 9X9 sudoku solver

#include<bits/stdc++.h>
#define N 9
using namespace std;

//for countings recursive calls
int recursiveCounts = 0;


//to check assigned num is safe or not? 
bool isSafe(int row, int column, int num, int sudoku[N][N]);

//check if all assigned? if not, refers to nearest unassigned position
bool allAssigned(int sudoko[N][N], int& row, int& cloumn);



//recursive function to solve sudoku, returns false if not possible
bool solveSudoku(int sudoku[N][N]){
	//counting recusive_calls	
	recursiveCounts++;
	
	int row=0;
	int column=0;
	
	//if all location assigned
	if(allAssigned(sudoku, row, column)){
		return true;
	}
	//if not, then row & column at nearest not assigned location
	
	//trying all possible values for the location
	for(int i=1;i<=9;i++){
		if(isSafe( row, column, i, sudoku)){
			
			//temperory assigned
			sudoku[row][column] = i;
			
			if(solveSudoku(sudoku)){
				return true;
			}
			else{
				//if leads to a wrong solution, then make it unassigned again
				sudoku[row][column] = 0;
			}
			
		}
	}
	return false;
}


bool allAssigned(int suduko[N][N], int& row, int& column){
	for(row=0; row<N; row++){
		for(column=0; column<N; column++){
			if(suduko[row][column] == 0){
				return false;
			}
		}
	}
	//if all assigned
	return true;
}

// a position's value is safe, if no same number:
// 1. in row
// 2. in column
// 3. in grid(3X3)
bool isSafe(int row, int column, int num, int sudoku[N][N]){
	//in row
	for(int i=0;i<N;i++){
		if(sudoku[row][i]==num && i!=column){
			return false;
		}
	}
	//in column
	for(int i=0;i<N;i++){
		if(sudoku[i][column]==num && i!=row){
			return false;
		}
	}
	//in grid(3X3)
	int gridStartRow = row - row%3;
	int gridStartColumn = column - column%3;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(sudoku[i+gridStartRow][j+gridStartColumn]==num){
				return false;
			}
		}
	}
	
	//if no match found, it is safe
	return true;
}



void printSudoku(int sudoku[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<sudoku[i][j]<<" ";
		}
		cout<<endl;
	}
}


int main(){
	cout<<"Hi there, I am sudoku solver."<<endl;
	cout<<"Enter the sudoku elements, 0 for unavailable elements : \n";
	int sudoku[N][N];
	//input
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>sudoku[i][j];
		}
	}
	cout<<endl;
	cout<<"The given unsolved sudoko : \n";
	printSudoku(sudoku);	
	cout<<endl;
	
	
	if(solveSudoku(sudoku)==true){
		cout<<"The solved sudoko : \n";
		printSudoku(sudoku);
		cout<<"\n This took "<<recursiveCounts<<" recursive calls."<<endl;
	}
	else{
		cout<<"Sorry, but this sudoku has no solution"<<endl;
	}
	
}
