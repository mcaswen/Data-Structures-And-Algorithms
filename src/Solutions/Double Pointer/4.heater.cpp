//leetcode 475

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findRadius(vector<int>& houses, vector<int>& heaters) {
        
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());

    int p1 = 0;
    int p2 = 0;

    int ans = 0;

    while (p1 < houses.size()) {


        while (p2 < heaters.size() - 1 && (p2 + 1 <= heaters.size() - 1 && (abs(houses[p1] - heaters[p2]) >= abs(houses[p1] - heaters[p2+1]))) ) {

            p2++;

        }

        ans = max(ans, houses[p1] - heaters[p2]);
        
        p1++;

    }

    return ans;

}