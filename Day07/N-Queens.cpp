#include <vector>
#include <string>
using namespace std;

void solve(int col, int n, vector<string>& b, vector<vector<string>>& res,
           vector<int>& r, vector<int>& d1, vector<int>& d2){
    if(col == n){ res.push_back(b); return; }
    for(int i = 0; i < n; i++){
        if(r[i] || d1[i+col] || d2[n-1+col-i]) continue;
        b[i][col] = 'Q';
        r[i] = d1[i+col] = d2[n-1+col-i] = 1;
        solve(col+1,n,b,res,r,d1,d2);
        b[i][col] = '.';
        r[i] = d1[i+col] = d2[n-1+col-i] = 0;
    }
}
