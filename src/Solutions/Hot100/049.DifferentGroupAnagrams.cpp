#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>

/// 本道题中，需要将不同的单词分组，每组单词需要满足：构成单词的字母完全相同，顺序任意
/// 于是容易联想到使用哈希表来存储字母集合，并建立 集合 - 单词组的映射
/// 每一个单词组，都会对应一个存储单词组中单词的字母集合
/// 于是需要一个哈希算法构造这个字母集合
/// 首先想到位运算，但位运算无法表示存在相同字母的单词
/// 这里通过排序法，因为排序后的单词构成的字母集合是唯一的
/// 复杂度是O(n * k * logk)
/// 也可以通过桶数组计数+数组哈希算法，或者干脆使用#或任意符号隔离计数的数字来构建字符串，这两个算法的复杂度是O(n * k)
/// 考虑到最优哈希性能（使用整数），还可以使用前26个质数的乘积来构造（唯一分解定理），然而这会引入溢出问题，取模则会引入冲突问题
/// 再优化的话就要引入自定义结构体，不过实现复杂，这里不作实现
/// 最后来考虑遍历时的判断，即对于每个单词，判断其字母集合是否已在表中存在
/// 若集合存在，则入组
/// 若不存在，则新建组
/// 最后遍历表值，加入vector即可

using namespace std;

vector<vector<string> > Solve(vector<string>& strs);

int main()
{
    vector<string> strs = vector<string>();
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s; cin >> s;
        strs.push_back(s);
    }

    auto anss = Solve(strs);
    for (auto& vec: anss)
    {
        for (auto& str: vec)
        {
            cout << str << " ";
        }
        cout << endl;
    }
}

vector<vector<string> > Solve(vector<string>& strs)
{   
    unordered_map <string, vector<string> > alphaMap;
    vector<vector<string> > anss;

    for (auto& str: strs)
    {
        string set = str;
        sort(set.begin(), set.end());

        alphaMap[set].push_back(str);
    }

    for (auto& [key, value]: alphaMap)
    {
        anss.push_back(value);
    }

    return anss;
}