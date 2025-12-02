#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
vector <int> presummod = vector <int>(1e5+5, 0);
unordered_map <int, int> mp;

int minSubarray(vector<int>& nums, int p) {
    
    int mod;
    mp[0] = -1;
    for (int i = 0; i < nums.size(); i++) {

        presummod[i] = (i == 0 ) ? nums[0] % p : (presummod[i-1] + nums[i]) % p;
        if (i == nums.size() - 1) mod = presummod[i];

    }
    
    if (mod == 0) return 0;

    int ans = 0x3f3f3f3f;

    for (int i = 0; i < nums.size(); i++) {

        int aim = (presummod[i] + p - mod) % p;

        if (mp.count(aim)) ans = min(ans, i - mp[aim]);
        
        mp[presummod[i]] = i;

    }

    return ans == 0x3f3f3f3f ? -1 : ans;

}