#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector <int> nums(1e5+5, 0);
unordered_map <int, int> mp;

int main() {

    int n;
    cin >> n;

    mp[0] = -1;
    int ans = 0;

    for (int i = 0, sum = 0; i < n; i++) {

        cin >> nums[i];

        if (nums[i] > 0) {

            sum += 1;

        } else if (nums[i] < 0) {

            sum += -1;

        } else {

            sum += nums[i];

        }

        if (mp.count(sum)) ans = max(ans, i - mp[sum]);

        if (!mp.count(sum)) mp[sum] = i;

    }

    cout << ans << endl;

}