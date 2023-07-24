#include <iostream>
using namespace std;
int grid[9][9] = {{0, 4, 0, 0, 5, 0, 1, 0, 3},
                  {0, 0, 3, 0, 0, 9, 5, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0, 0, 0},
                  {0, 5, 0, 0, 7, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 8, 7, 0, 9},
                  {0, 7, 0, 9, 0, 1, 3, 0, 8},
                  {7, 0, 0, 6, 0, 0, 0, 3, 5},
                  {0, 0, 0, 0, 4, 7, 0, 0, 0},
                  {0, 0, 9, 0, 8, 5, 2, 7, 0}};
                  
bool isSafe(int row, int col, int grid[9][9], int val){
        for(int i = 0;i < 9;i++){
            //row check
            if(grid[row][i] == val)
            return false;
            
            if(grid[i][col] == val) 
            return false;
            
            if(grid[3*(row/3) + i/3][3*(col/3) + i%3] == val)
            return false;
        }
        return true;
    }
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[9][9])  
    { 
        // Your code here
        for(int row = 0;row < 9;row++){
            for(int col = 0;col < 9;col++){
                //cell empty
                if(grid[row][col] == 0){
                    for(int val = 1; val<=9;val++){
                        if(isSafe(row, col, grid, val)){
                            grid[row][col] = val;
                            
                            bool aageSolutionPossible = SolveSudoku(grid);
                            if(aageSolutionPossible){
                                return true;
                            }
                            else{
                                grid[row][col] = 0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
int main(){
SolveSudoku(grid);
for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    return 0;
}