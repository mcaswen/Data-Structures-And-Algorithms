//leetcode 881
#include <iostream>
#include <algorithm>
using namespace std;

int numRescueBoats(vector<int>& people, int limit) {
 
    int n = people.size();

    sort(people.begin(), people.end());

    int le = 0, ri = n - 1;
    int ans = 0;
    while (le <= ri) {

        if (le == ri) {

            ans++;
            break;
        
        }

        if (people[le] + people[ri] <= limit) {

            le++;
            ri--;

        } else {

            ri--;

        }

        ans++;

    }

    return ans;

}