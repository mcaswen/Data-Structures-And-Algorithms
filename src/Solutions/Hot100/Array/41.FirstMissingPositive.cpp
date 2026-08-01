#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

/// 不断更新数组的最小范围
/// 错解：维护已发现区间，无法顾及之前发现的重要数

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        if (nums.empty()) return 1;

        int first = 1;
        int minLeft = 0;
        int lastMinRight = 0;

        for (auto num: nums)
        {
            lastMinRight = max(num, lastMinRight);
        }

        int minRight = lastMinRight;
        for (int i = 0; i < nums.size(); i++)
        {
            if (minLeft == minRight - 1)
            {
                minLeft = minRight;
                first = minLeft + 1;
                minRight = lastMinRight;
                continue;
            }

            if (nums[i] <= minRight && nums[i] > 0)
            {
                if (nums[i] == minLeft + 1)
                {
                    minLeft = nums[i];
                    first = minLeft + 1;
                }
                else 
                {
                    lastMinRight = minRight;
                    minRight = nums[i];
                }
            }
        }

        return first;

    }
};

/// 正解：对于包含n个数字的数组，缺失的第一个正数一定在[1, n+1]之间
/// 于是我们把[1, n]的每一个数字放在对应的[0, n-1]位置上，从1 - n遍历检查哪个没放对，哪个就是答案
/// 如果1 - n都对，答案就是 n + 1
/// 本质是把数组当作原地哈希表
/// 交换时，注意交换后的元素还需要继续放在正确位置，所以用 while 循环
/// 如果交换前和交换后的元素相同也要中止，否则会死循环
/// 注意：交换之后的下标就代表了交换后的元素，下标 i 不需要再和 nums[i] - 1 交换，否则就回到了交换到正确位置的元素上，而不是需要交换的元素上

class Solution2 {
public:
    void swap(vector<int>& nums, int a, int b)
    {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    int firstMissingPositive(vector<int>& nums) 
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
            {
                swap(nums, i, nums[i] - 1);
            }
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != i + 1)
            return i + 1;
        }

        return nums.size() + 1;
    }
};
