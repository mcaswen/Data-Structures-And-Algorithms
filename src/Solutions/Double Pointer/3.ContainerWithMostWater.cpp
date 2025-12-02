//leetcode 11
#include <iostream>

using namespace std;

int maxArea(vector<int>& height) {
        
    int n = height.size();
    int le = 0, ri = n - 1;
    int ans = 0;

    while (le < ri) {

        int mini = min(height[le], height[ri]);
        ans = max(ans, mini * (ri - le));

        if (mini == height[le]) le++;
        else ri--;

    }

    return ans;

}