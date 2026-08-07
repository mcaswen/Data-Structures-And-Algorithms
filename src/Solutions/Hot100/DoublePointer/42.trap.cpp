#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

/// 因为每次遇到高于当前 buttom 的右墙才会触发计算
/// 所以考虑使用用单调栈来维护每一层的索引
/// 遇到高于左墙的右墙时，核心计算的水量差是左右墙较低的哪一个 - 被弹出的底部之间的中间层，再乘上当前左右墙之间的距离
/// 然后未被计算的，距离更远的后续左右墙，与当前底部之间确实还会有水量差，但会在之后的更新中保证被计算
/// 它们会继续计算更上层的水量，以及宽度也会覆盖当前底部，直到真正的最高左右墙间水量被计算完毕

class Solution {
public:
    int trap(vector<int>& height) 
    {
        int ans = 0;
        stack<int> s;

        for (int i = 0; i < height.size(); i++)
        {
            if (s.empty() || height[i] <= height[s.top()])
            {
                s.push(i);
            } 
            else if (height[i] > height[s.top()])
            {
                while (!s.empty() && height[i] > height[s.top()])
                {
                    // 每次都计算弹出时，左右墙较低的哪一个 - 被弹出的底部之间的中间层所对应的水量
                    // 也就是 水量 = (右墙 - 左墙之间的距离) * 中间层
                    // 这样可以保证不会重复或者少算

                    int bottom = s.top();
                    s.pop();

                    if (s.empty()) break; // 当前没有左墙，无需计算

                    ans += (i - s.top() - 1) * (min(height[s.top()], height[i]) - height[bottom]);
                }

                s.push(i);
                cout << endl;
            }
        }
        
        return ans;
    }
};