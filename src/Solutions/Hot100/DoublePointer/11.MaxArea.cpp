#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

/// 双指针，左指针和右指针向中间遍历
/// 核心在于越往中间走，x轴容量越小，所以移动较长边不可能增大面积
/// 移动较短边才可能增大面积

class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int left = 0;
        int right = height.size() - 1;
        int curMin = min(height[left], height[right]);
        int max = (right - left) * curMin;

        while (left < right)
        {
            curMin = min(height[left], height[right]);
            max = std::max((right - left) * curMin, max);

            // 更新更短的那一边
            if (height[left] > height[right])
            {
                right--;
            } else left++;
        }

        return max;
    }
};

