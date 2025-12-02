#include <iostream>
#include <vector>

using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
        
    int l = 1;
    int r = *max_element(piles.begin(), piles.end());
    int ans = 0;
    
    while (l <= r) {

        int mid = l + ((r - l) >> 1);

        if (check(piles, mid, h)) {

            ans = mid;
            r = mid - 1;

        } else {

            l = mid + 1;

        }

    }

    return ans;

}

bool check(vector <int>& piles, int v, int h) {

    int hours = 0;

    for (auto p: piles) {

        hours += (p + v - 1) / v;

    }

    return hours <= h;

}