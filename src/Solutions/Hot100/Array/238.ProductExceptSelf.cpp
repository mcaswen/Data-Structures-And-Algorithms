#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

/// 求数组每个位置除自己之外所有元素的积，要求On且不用除法
/// 联想到前缀积，每个位置求一遍前缀，求一遍后缀，二者相乘即可

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();

        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);
        prefix[0] = 1;
        suffix[n - 1] = 1;
 

        for (int i = 1; i < n; ++i)
        {
            // 前缀积不应该包括位置自己，因为求的是除了自己之外的乘积
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        for (int i = n - 2; i >= 0; --i)
        {
            // 后缀积同理
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        vector<int> ans(n, 0);
        // 前缀积与后缀积相乘
        for (int i = 0; i < n; ++i)
        {
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;        
    }
};

/// 优化O1空间版：只保存前缀积
/// 后缀积用一个变量累积，直接乘在前缀积上即可
class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();

        vector<int> ans(n, 0);
        ans[0] = 1;

        for (int i = 1; i < n; ++i)
        {
            // 前缀积不应该包括位置自己，因为求的是除了自己之外的乘积
            ans[i] = ans[i-1] * nums[i-1];
        }

        // 后缀积不用一个数组保存，直接一个变量保存
        int suffix = 1;

        for (int i = n - 1; i >= 0; --i)
        {
            ans[i] *= suffix; // 直接乘上后缀积，效果相同
            suffix *= nums[i]; // 后缀积更新用i，下一次才会乘上，落后一次循环
        }

        return ans;        
    }
};