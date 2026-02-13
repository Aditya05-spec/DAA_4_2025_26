#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {

    unordered_map<int , bool> rowCheck;
    unordered_map<int , bool> upperDiagonalCheck;
    unordered_map<int , bool> lowerDiagonalCheck;
private:

    void storeSolution(vector<vector<char> > &arr , int n , vector<vector<string> > &ans) {
        vector<string> temp;
        for(int i=0 ; i<n ; i++) {
            string output = "";
            for(int j=0 ; j<n ; j++) {
                output.push_back(arr[i][j]);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }

    bool isSafeQueen(int row , int col , vector<vector<char> > &arr , int n){
        if(rowCheck[row] == true) {
            return false;
        }

        if(upperDiagonalCheck[n+1+col-row] == true) {
            return false;
        }

        if(lowerDiagonalCheck[row+col] == true) {
            return false;
        }

        return true;
    }




    void solveQueen(vector<vector<char> > &arr , int col , int &n , vector<vector<string> > &ans) {
    //Base case
    if(col >= n) {
        storeSolution(arr , n , ans);
        return;
    }

    for(int row = 0; row<n ; row++) {
        if(isSafeQueen(row , col , arr , n)) {
            // place the queen on the current row
            arr[row][col] = 'Q';
            rowCheck[row] = true;
            lowerDiagonalCheck[row+col] = true;
            upperDiagonalCheck[n+1+col-row] = true;

            // Recursive call
            solveQueen(arr , col+1 , n , ans);

            //Backtracking
            rowCheck[row] = false;
            lowerDiagonalCheck[row+col] = false;
            upperDiagonalCheck[n+1+col-row] = false;
            arr[row][col] = '.';
        }
    }
}


public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<vector<char> > arr(n , vector<char>(n,'.'));
        int col = 0;
        solveQueen(arr , col , n , ans);

        return ans;

    }
};
