//leetcode 42
#include <iostream>

using namespace std;

vector <int> LeftMax = vector <int> (2e4 + 5, 0);
vector <int> RightMax = vector <int> (2e4 + 5, 0);

//未优化，使用两个数组维护前后缀信息
int trap(vector<int>& height) {
    
    int n = height.size();

    for (int i = 1; i < n; i++) {

        LeftMax[i] = max(LeftMax[i-1], height[i-1]);
        

    }

    for (int i = n - 2; i >= 0; i--) {  

        RightMax[i] = max(RightMax[i+1], height[i+1]);

    }

    int sum = 0;

    for (int i = 1; i < n - 1; i++) {

        int mini = min(LeftMax[i], RightMax[i]);
        sum += (height[i] >= mini) ? 0 : (mini - height[i]);

    }

    return sum;

}

//优化版，无需辅助数组，单调性分析+双指针中移
int trap2(vector <int>& height) {

    int n = height.size();

    int le = 1, ri = n - 2, lmax = height[0], rmax = height[n-1];
    int sum = 0;

    while (le <= ri) {

        if (lmax <= rmax) {

            sum += (height[le] >= lmax ) ? 0 : lmax - height[le];
            le++;
            lmax = max(lmax, height[le-1]);

        } else {

            sum += (height[ri] >= rmax) ? 0 : rmax - height[ri];
            ri--;
            rmax = max(rmax, height[ri+1]);

        }

    }

    return sum;

}