#include <bits/stdc++.h>
using namespace std;

void solve(int col, int n, vector<string>& board,
           vector<vector<string>>& res,
           vector<int>& left, vector<int>& d1, vector<int>& d2){
    if(col == n){
        res.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(left[row] || d1[row+col] || d2[n-1+col-row]) continue;
        board[row][col] = 'Q';
        left[row] = d1[row+col] = d2[n-1+col-row] = 1;
        solve(col+1,n,board,res,left,d1,d2);
        board[row][col] = '.';
        left[row] = d1[row+col] = d2[n-1+col-row] = 0;
    }
}
