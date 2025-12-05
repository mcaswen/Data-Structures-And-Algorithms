#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>

/// 本道题中，要求不含重复字符的最长子串长度
/// 对于遍历子串的方式，首先想到的是滑动窗口
/// 从0, 0开始扩右边界，再用一个unordered_set维护滑动窗口中的字符类型
/// 如果遇到重复字符，就记录答案，让左边界跳转到重复字符之后，继续扩右边界
/// 所以这里就注意到，不能使用deque来模拟窗口，因为在deque里跳转操作很昂贵
/// 先要找到重复字符(O(n))，还要连续出队左边界来跳转，又是O(n)，整体就是O(n^2)，对 5 * 10^4 的数据量来说不可接受
/// 于是就想到用双指针来模拟，并用unordered_map来记录字符的索引位置(char - int的映射)
/// 这样只要直接将左指针移动到重复字符的索引的下一个位置即可，这是O(1)的操作
/// 总体就是O(n)的时间复杂度，O(n)的空间复杂度
/// 实现时注意：
/// 1. 如何清除过期的索引映射？
/// 不需要真正清除，只需要在查找时看字符的索引是否在当前窗口内（即是否 >= 左指针的值），并更新重复字符的新索引
/// 这样依旧是O(1)的查找，但防止了找到已经过期的字符

using namespace std;

int Solve(string s);

int main()
{
    string s;
    cin >> s;
    cout << Solve(s) << endl;
}

int Solve(string s)
{
    int leftPointer = 0;
    int rightPointer = 0;
    unordered_map<char, int> map = unordered_map<char, int>(); // 字符 - 索引的映射

    int ans = 0;

    while (rightPointer < s.size())
    {
        int rightPos = s[rightPointer];

        if (map.find(rightPos) != map.end() && map[rightPos] >= leftPointer) // 若字符已经存在，且索引在左指针之后（未过期）
        {
            int pos = map[rightPos];
            leftPointer = pos + 1; //移动左指针
        } 

        // 更新索引，右指针和答案
        ans = max(ans, rightPointer - leftPointer + 1);
        map[rightPos] = rightPointer;
        rightPointer++;
    }

    return ans;
}

// pwwkew
