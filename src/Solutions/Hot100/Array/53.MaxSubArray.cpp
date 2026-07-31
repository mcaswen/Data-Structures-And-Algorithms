#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

// 核心思想：如果前面的累加和已经是负数，就不值得把它接到可能成为答案的最终子数组的前面，应该把它丢掉
// 对于连续子数组，遍历时遇到一个新数，只有两种操作：要么把它加进来，要么把原来的已有数组丢掉，从新数开始
// 那么我们只需要判断，如果累加和小于0了，它加上新数就一定比新数自己以及之后可能的更大序列产生的更大和小，就把它丢掉
// 如果累加和大于0，说明它带来的收益是正的，就把它保留，加上新数
// 也就是说，我们本质上看的就是已有数组是否值得保留这件事


using namespace std;

class Solution {
public:
   int maxSubArray(vector<int>& nums)
    {
        int curSum = nums[0];
        int maxSum = nums[0];
        
        for (int i = 1; i < nums.size(); ++i)
        {
            // 以当前位置结尾的最大子数组，要么从当前位置开始，要么接在之前的最大子数组后面
            curSum = std::max(nums[i], curSum + nums[i]);

            // 在所有“以某个位置结尾的最大子数组”中，再选一个全局最大的
            maxSum = std::max(maxSum, curSum);
        }

        return maxSum;
    }
};
