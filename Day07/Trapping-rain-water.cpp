#include <vector>
using namespace std;

int trap(vector<int>& h) {
    int l = 0, r = h.size() - 1, lmax = 0, rmax = 0, ans = 0;
    while(l < r){
        if(h[l] < h[r]){
            lmax = max(lmax, h[l]);
            ans += lmax - h[l++];
        } else {
            rmax = max(rmax, h[r]);
            ans += rmax - h[r--];
        }
    }
    return ans;
}
