#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map <int, int> mp;

int longestWPI(vector<int>& hours) {

    int sum = 0, ans = 0;
    mp[0] = -1;

    for (int i = 0; i < hours.size(); i++) {

        sum += hours[i] > 8 ? 1 : -1;

        if (sum > 0) ans = max(ans, i + 1);
        else {

            int aim = sum - 1;
            if (mp.count(aim)) ans = max(ans, i - mp[aim]);

        }

        if (!mp.count(sum)) mp[sum] = i;

    }

    return ans;

}