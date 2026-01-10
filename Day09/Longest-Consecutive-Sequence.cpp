#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end());
    int ans = 0;

    for(int x : st){
        if(!st.count(x - 1)){
            int curr = x, streak = 1;
            while(st.count(curr + 1)){
                curr++;
                streak++;
            }
            ans = max(ans, streak);
        }
    }
    return ans;
}
