#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) 
    {
        auto minLeft = s.begin();
        auto minRight = s.begin();
        unordered_map<char, int> tmap; // 维护t中字母存在性以及数量
        int minLength = INT_MAX;

        for (const auto c: t)
        {
            tmap[c]++;
        }
        
        unordered_map<char, int> tempTmap = tmap;
        int curLength = 0;
        int curNum = t.size();

        /// 更新流程：
        /// 右指针前进，同时更新字符-字符数量映射关系和目标串内未包含字符数量
        /// 若未包含字符数量小于等于0，记录当前答案
        /// 同时把左指针对应的字符和1加回来，之后跳转到下一个目标串内的字符

        bool isFirstWindow = true;

        for (auto left = s.begin(), right = s.begin(); left != s.end(); left++)
        {
            // 右指针前进中的更新流程
            while (right != s.end() && curNum > 0)
            {
                // 当需要的目标字符对应数量大于0时，说该字符被需要，那么未获得目标字符数量--
                // 若小于0，则说明冗余，未获得目标字符数量不变
                // 但是目标字符对应数量总是需要--，因为它代表这个字符实际的需要数量，小于0表达冗余。

                if (tmap[*right] > 0)
                {
                    if (tempTmap[*right] > 0)
                    {
                        curNum--;
                    }

                    tempTmap[*right]--;
                }

                right++; // 代表下一个未处理的字符，总是++
            }
            
            // 此时窗口内部剩余未获得目标字符的数量为0，更新答案
            if (curNum <= 0)
            {
                curLength = right - left;
                if (curLength < minLength)
                {
                    minLeft = left;
                    minRight = right;
                    minLength = curLength;
                }
            } else break; // right == s.end()

            // 若目标串中有当前字符，且下一轮left右移
            if (tmap[*left] > 0)
            {
                // 当前字符退出窗口，需要的数量 +1
                tempTmap[*left]++;

                // 当前字符确实被需要
                if (tempTmap[*left] > 0)
                {
                    curNum++;
                }
            }
        }

        if (minLength == INT_MAX) return "";
        return string(minLeft, minRight); // right 代表下一个未处理的字符，不用 +1，直接返回
    }
};