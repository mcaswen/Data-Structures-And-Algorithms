#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

/// 目标 Onlogn 复杂度完成三数之和
/// 从数组其中一个数出发，利用单调性保证左右指针的移动可以找到答案
/// 具体地说，i=a1，从左往右遍历排序后数组，同时-a1 = a2 + a3 = sum，。
/// 在确定 a1 时，则左指针 a2 放在 i+1，右指针 a3 放在 n-1，向中间移动
/// 若 cur = a2 + a3 比 sum 小，由单调性知只要移动左指针，右指针同理
/// 从 i + 1开始找，因为 (0, i] 范围可以保证已经搜索完毕
/// 但还要注意去重问题，但排序后数组相同元素一定相邻，故用 nums[i] == nums[i-1] 排除即可

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ansArr;

        for(int i = 0; i < nums.size(); ++i)
        {
            // 去重
            if (i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }

            int sum = -nums[i];
            int left = i + 1;
            int right = n - 1;

            while (left < right)
            {
                int cur = nums[left] + nums[right];
                if (cur < sum)
                {
                    left++;
                } else if (cur > sum)
                {
                    right--;
                } else 
                {
                    vector<int> ans {nums[i], nums[left], nums[right]};
                    ansArr.push_back(ans);
                    
                    // 只当找到答案后去重，因为这些值都使用过所以可以安全跳过
                    // 否则可能跳过没有尝试过的值
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right--;
                    }

                    // 可能还有其他答案，继续寻找下一个
                    left++;
                    right--;
                }

            }
        }

        return ansArr;
    }
};