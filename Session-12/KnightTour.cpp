#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
  public:
    vector <int> nx = {2, 1, -1, -2, -2, -1, 1, 2}; //for rows
    vector <int> ny = {1, 2, 2, 1, -1, -2, -2, -1};  //for columns
    vector <vector<int>> board;
    int n;
    
    bool isSafe(int x, int y)
    {
        return (x>=0&&y>=0&&x<n&&y<n&&board[x][y]==-1);
    }
    
    bool formBoard(int x, int y, int step)
    {
        if(step==n*n)
        return true;
        
        for(int i=0; i<8; i++)
        {
            int dx=x+nx[i];
            int dy=y+ny[i];
            
            if(isSafe(dx, dy))
            {
                board[dx][dy]=step;
                if(formBoard(dx, dy, step+1))
                return true;
                board[dx][dy]=-1;
            }
        }
        return false;
    }
    vector<vector<int>> knightTour(int n) {
        this->n=n;
        board.assign(n, vector<int>(n, -1));
        board[0][0]=0;
        if(formBoard(0, 0, 1))
        return board;
        return {};
    }
};
int main()
{
    int n;
    cin >> n;
    Solution obj;
    vector<vector<int>> board=obj.knightTour(n);
    for(const auto& out: board)
    {
        for(const auto& el: out)
        cout << el << "   ";
        cout << endl;
    }
}