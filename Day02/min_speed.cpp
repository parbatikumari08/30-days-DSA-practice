#include <bits/stdc++.h>
using namespace std;

bool can(vector<int>& dist, double hour, int speed){
    double time = 0;
    for(int i = 0; i < dist.size(); i++){
        double t = (double)dist[i] / speed;
        if(i != dist.size() - 1)
            time += ceil(t);
        else
            time += t;
    }
    return time <= hour;
}

int minSpeedOnTime(vector<int>& dist, double hour) {
    int l = 1, r = 1e7, ans = -1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(can(dist, hour, mid)){
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return ans;
}
