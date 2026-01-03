#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& h) {
    stack<int> st;
    int n = h.size(), ans = 0;

    for(int i=0;i<=n;i++){
        int cur = (i==n ? 0 : h[i]);
        while(!st.empty() && h[st.top()] > cur){
            int height = h[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            ans = max(ans, height * width);
        }
        st.push(i);
    }
    return ans;
}
