#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

/// 本质是找到第一个 >= target 的位置
/// 所以退出循环时left > right，且直接代表该位置，直接返回left

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        if (target < nums[0]) return 0;
        else if (target > nums[nums.size() - 1]) return nums.size();

        int left = 0;
        int right = nums.size() - 1;
        int mid = (right + left) / 2;

        // 用 < : 左闭右开区间，== 时视为搜索区间里已经没有元素
        // 用 <= : 闭区间，== 时搜索区间里还有一个相等时的元素
        while (left <= right)
        {
            mid = (right + left) / 2;

            if (nums[mid] > target)
            {
                right = mid - 1;
            } else if (nums[mid] < target)
            {
                left = mid + 1;
            } else
            {
                return mid;
            }
        }
        
        return left;
    }
};