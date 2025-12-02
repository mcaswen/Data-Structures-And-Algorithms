#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map <int, int> mp;

int subarraySum(vector<int>& nums, int k) {
    
    int ans = 0;
        
    for (int sum = 0, i = 0; i < nums.size(); i++) {

        sum += nums[i];
        int aim = sum - k;

        ans += mp.count(aim);
        mp[sum]++;

    }

    return ans;

}