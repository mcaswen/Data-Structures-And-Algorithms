#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

/// 本道题中，要求数字连续的最长序列，也就是忽略顺序，找最长的连续正整数的序列的长度
/// 要求O(n)，即一次遍历内完成
/// 容易想到哈希表存信息，空间换时间
/// 那么，需要存储哪些信息呢？
/// 在数组中，我们在遍历中对每个数字都要进行一些处理，且影响连续正整数序列的关键在于每个数字的前一个，以及后一个
/// 那么可以想到，我们可以存储一个数字在其当前序列当中所处在的位置，即建立数字-位置的映射
/// 更新过程就会是，先找前一个数字，（若存在）加上前一个数字的位置，再找后一个数字，（若存在）把后一个数字加上当前位置，并循环地更新后一个数字之后的所有数字
/// 这样的双向更新可以确保答案不遗漏
/// 对于一个新数字，我们先看他是否存在，若存在则跳过（数字是否重复不影响答案的正确性），若不存在则把他入表，将位置初始化为1，说明他在处理前是序列中的第一个
/// 然后，我们寻找他的前一个数字，即map[nums[i] - 1]，检查存在性：
    /// 若存在，则将当前数字的位置更新为map[nums[i] - 1] + 1，即前一个数字的后一个，前一个数字本身不用动
/// 之后，我们寻找他的后一个数字，即map[nums[i] + 1]，检查存在性：
    /// 若存在，则后一个数字本身也可能拥有一个位置
    /// 那么这时候思考这个位置的意义，它实际上是之前更新的旧序列当中的位置
    /// 那么我们就需要把这个后数字加上当前数字的位置值来更新，并循环更新它之后的所有数字，并全部 + 当前数字的位置值。
/// 循环往复，即可得到答案。
/// 这样最差时间复杂度是O(n^2)，平均时间复杂度是O(n)，空间复杂度是O(n)
/// 超时了呜呜呜

using namespace std;

int Solve(vector<int>& nums);
int Solve2(vector<int>& nums);

int main()
{
    vector <int> nums;

    int n; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int num; cin >> num;
        nums.push_back(num);
    }

    cout << Solve2(nums) << endl;
}

int Solve(vector<int>& nums)
{
    if (nums.empty()) return 0;

    unordered_map <int, int> map = unordered_map <int, int>(); // 数字 - 位置的映射
    int n = nums.size();
    int ans = 1;

    for (int i = 0; i < n; ++i)
    {
        int cur = nums[i];

        if (map.find(cur) != map.end()) continue;

        if (map.find(cur - 1) != map.end()) // 前一个数字
        {
            map[cur] = map[cur - 1] + 1;
            ans = map[cur] > ans ? map[cur] : ans;
        } 
        else map[cur] = 1;

        if (map.find(cur + 1) != map.end()) // 后一个数字
        {
            int next = cur + 1; // 拿后一个数字
            while (map.find(next) != map.end()) // 循环找后一个数字的已存在序列
            {
                map[next++] += map[cur];
            }

            ans = map[next - 1] > ans ? map[next - 1] : ans;
        }
    }

    return ans;
}

/// 没办法，超时了就考虑优化
/// 那么，这个解法当中，是否有信息是冗余的呢？一般记录了多余信息，就可能会导致额外的操作并增加时间复杂度
/// 再来看题目，只要求了序列的长度，但我们却多记录了序列中每个数字的位置，这显然是冗余的
/// 要想知道长度，其实我们只需要记录序列里的边界，即左边界和右边界，再通过右边界 - 左边界 + 1就能得到长度
/// 再来想更新：“前一个后一个”的逻辑仍然成立，但是由于我们只更新边界，那么对于每一个数字：
/// 我们只需要先拿到前一个数字的左边界，和后一个数字的右边界，就能完成更新
/// 同时别忘了更新完毕后，这次不是前后数字的边界了，而是整个序列的两端边界也要根据这次更新的结果来更新
/// 每次更新都是对序列边界的拓展，遍历完毕后就能得到最长边界
/// 那么映射关系就很明显了：数字 - pair <当前序列左边界，当前序列右边界>的映射
/// 对于每一个数字，先把映射初始化成自身 - pair <自身，自身>，然后按照上述逻辑更新就行
/// 由于左右也会同步更新，所以就能保证可以找到所有可能的连续序列
/// 优化在哪？就在我们之前循环找后一个数字的已存在序列并更新。每次更新都是O(n)级别的操作，累计一下就是O(n^2)了
/// 使用现在的解法，只需O(1)更新左右边界，复杂度就是O(n)
/// 空间复杂度同样是O(n)

int Solve2(vector<int>& nums)
{
    if (nums.empty()) return 0;

    unordered_map <int, pair<int, int> > map = unordered_map <int, pair<int, int> >(); // 数字 - pair <当前序列左边界，当前序列右边界>的映射
    int n = nums.size();
    int ans = 1;

    for (int i = 0; i < n; ++i)
    {
        int cur = nums[i];

        if (map.find(cur) != map.end()) continue;

        map[cur] = make_pair(cur, cur);

        if (map.find(cur - 1) != map.end()) // 前一个数字
        {
            map[cur].first = map[cur - 1].first; // 把 当前数字左边界 更新为 前一个数字的左边界
        } 

        if (map.find(cur + 1) != map.end()) // 后一个数字
        {
            map[cur].second = map[cur + 1].second; // 把 当前数字右边界 更新为 后一个数字的右边界
        }

        // 接下来是同步更新序列左端的右边界和序列右端的左边界
        int curBegin = map[cur].first;
        int curEnd = map[cur].second;

        map[curBegin].second = curEnd;
        map[curEnd].first = curBegin;

        // 记录答案
        int curLength = curEnd - curBegin + 1;
        ans = max(curLength, ans);
    }

    return ans;
}

// 10
// 0 3 7 2 5 8 4 6 0 1