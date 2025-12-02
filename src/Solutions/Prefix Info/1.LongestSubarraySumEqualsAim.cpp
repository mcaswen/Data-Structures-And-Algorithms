#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
typedef long long ll;

vector <ll> nums(1e5+5, 0);
vector <ll> presum(1e5+5, 0);
unordered_map <ll, int> mp; 

int main() {

    int n, k;
    cin >> n >> k;
    mp[0] = -1;
    
    for (int i = 0; i < n; i++) {

        cin >> nums[i];
        presum[i] = (i == 0 ? 0 : presum[i-1]) + nums[i];
        
        if (mp.count(presum[i]) == 0)
            mp[presum[i]] = i;

    }

    int ans = 0;

    for (int i = 0; i < n; i++) {

        int aim = presum[i] - k;
        if (mp.count(aim) == 1) {

            ans = max(ans, i - mp[aim]);

        }

    }

    cout << ans << endl;

}
