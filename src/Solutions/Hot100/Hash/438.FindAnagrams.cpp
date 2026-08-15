#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

/// 依旧排序确定异位性
/// 遍历数组的3元素子数组，复杂度n2logn
/// 超时了，改滑动窗口，存字母的种类->数量的map，以及符合要求的字母数量
/// 每次滑动时更新退出的和新进入的，如果种类->数量匹配目标字符串，符合要求的字母就++
/// 退出时注意，因为退出前字母数量不匹配，不简单用 != 判断，而是用 target[o] == curMap[o] + 1判断
/// 这样才能正确判断退出前符合要求，推出后不符合要求这种情况
/// 符合要求的字符种类数 == 目标字符串中的字符种类数时即为答案，push_back即可
/// 复杂度 On，空间复杂度O1\
/// 如果只有小写字母，可以考虑维护targetCount[26]和curCount[26]，每次滑动时对对应格子上的字母++--，并且完整比较即可，复杂度O(26n) 约等于 O(n)

class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        if (p.size() > s.size()) return vector<int>();

        unordered_map<char, int> target;
        unordered_map<char, int> curMap;
        int required = 0;

        vector<int> ans;

        for (auto c: p)
        {
            target[c]++;
        }
        
        int targetRequired = target.size();

        for (int i = 0; i < s.size() - p.size() + 1; i++)
        {
            // 处理进入
            if (i == 0)
            {
                for (int j = 0; j < p.size(); j++)
                {
                    char cur = s[j];
                    curMap[cur]++;

                    /// 当前窗口内对应字符数量与目标字符串的相应字符数量匹配，符合要求的字母数量++
                    if (target[cur] == curMap[cur]) required++;
                    // 如果超出还要--
                    if (target[cur] > 0 && target[cur] == curMap[cur] - 1) required--;
                }
            } else 
            {
                char cur = s[i + p.size() - 1];
                curMap[cur]++;

                /// 同理++
                if (target[cur] == curMap[cur]) required++;
                // 如果超出还要--
                if (target[cur] > 0 && target[cur] == curMap[cur] - 1) required--;
            }

            // 处理退出
            if (i > 0)
            {
                char o = s[i - 1];
                curMap[o]--;

                /// 退出时注意，因为退出前字母数量不匹配，不简单用 != 判断，而是用 target[o] == curMap[o] + 1判断
                /// 这样才能正确判断退出前符合要求，退出后不符合要求这种情况
                if (target[o] == curMap[o] + 1) required--;
                // 注意还有退出时正好符合要求的情况
                if (target[o] > 0 && target[o] == curMap[o]) required++;
            }

            // 符合要求的字符种类数 == 目标字符串中的字符种类数
            if (required == targetRequired) ans.push_back(i);
        }

        return ans;

    }
};