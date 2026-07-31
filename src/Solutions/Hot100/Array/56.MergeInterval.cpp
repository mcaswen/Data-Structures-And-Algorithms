#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

/// 对于合并区间问题，容易观察到对于要合并的区间，左区间的左端点总是小于右区间的左端点，左区间的右端点总是大于等于右区间的左端点
/// 但当合并时，合并后区间使用的右端点，来自左区间或者右区间都有可能（来自左区间的话，相当于右区间被左区间完全包围）
/// 于是需要用max()，右端点用它们之中更大的那一个
/// 顺序遍历就行，因为[左区间的左端点总是小于右区间的左端点],按照左端点先排序
/// 注意右区间被合并之后就不再考虑了，所以i = next，而不是i++


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end(),  [](const vector<int>& a, const vector<int>& b)
        {
            return a[0] < b[0];
        });
        
        vector<vector<int>> ans;

        for (int i = 0; i < intervals.size();)
        {
            vector<int> cur = intervals[i];
            int next = i+1;

            while (next < intervals.size() && cur[1] >= intervals[next][0])
            {
                cur[1] = max(cur[1], intervals[next][1]);
                next++;
            }
            
            i = next;
            ans.push_back(cur);
        }

        return ans;
    }
};