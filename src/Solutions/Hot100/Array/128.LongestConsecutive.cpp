#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

// 本质上是一个查询任务，对于查询首先想到集合
// 但是对于每个数字都查一遍最长序列就是n2
// 于是要想如何减少查询次数，观察得到每个序列当中，只要不是起点数字，都一定能找到其前置数字
// 那么对于所有能找到前置数字的数字都跳过查询，就能在不漏序列的情况下只查起点，减少时间复杂度
// 最后记录所有序列，max()拿到最长序列即可


class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> set(nums.begin(), nums.end());
        int maxLength = 0;

        for (auto it: set)
        {
            if (set.find(it - 1) != set.end())
            {
                continue;
            }

            int p = it;
            int curLength = 0;

            while (set.find(p++) != set.end())
            {
                curLength++;
            }

            maxLength = max(curLength, maxLength);
        }
        
        return maxLength;
    }
};