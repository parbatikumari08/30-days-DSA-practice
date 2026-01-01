#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int curr = nums[0], best = nums[0];
    for(int i = 1; i < nums.size(); i++){
        curr = max(nums[i], curr + nums[i]);
        best = max(best, curr);
    }
    return best;
}
