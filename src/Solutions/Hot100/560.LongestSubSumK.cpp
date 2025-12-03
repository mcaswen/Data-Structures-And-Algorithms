#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>

/// 本道题中，要求和为k的子数组数量，这涉及到大量的和查询，自然联想到前缀和
/// 以i开头，j结尾的子数组，其和大小即为j位置的前缀和 - (i - 1)位置的前缀和
/// 那么要对每个子数组都进行遍历，即先遍历j的前缀和，再以j为结尾遍历i的前缀和即可
/// 复杂度为O(n^2)，对于n <= 2 * 10^4 的数据量可接受（leetcode的oj确实让过了）
/// 注意具体实现中，如果用0-based前缀和数组，那么在处理0 - j范围时需要特判。
    /// 因为在 i = 1 时， j - (i - 1) 的前缀和就是 preSum[j] - preSum[0]，这是合法的，preSum[j] 本身包含0 - j 的和，减去0后即为 1 - j 的和
    /// 然而 i = 0 时，按照与上述逻辑相同的代码，我们仍需减去 i - 1 ，此时 i - 1 为 -1 ，数组越界不合法，所以需要特判
        /// 这实际上不是逻辑问题，而是数组的实现问题，因为数组不允许-1索引，而数学上我们可以认为preSum[-1] = 0
        /// 于是此时直接使用preSums[j]即可

using namespace std;

int Solve(vector<int>& nums, int k);
int Solve2(vector<int>& nums, int k);

int main()
{
    vector<int> nums = vector<int>();
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        int s; cin >> s;
        nums.push_back(s);
    }

    auto ans = Solve2(nums, k);
    cout << ans << endl;
}

int Solve(vector<int>& nums, int k)
{
    vector<int> preSums = vector<int>();
    preSums.push_back(nums[0]);
    int ans = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        int subSum = nums[i] + preSums[i-1];
        preSums.push_back(subSum);
    }

    for (int j = 0; j < preSums.size(); ++j)
    {
        for (int i = 0; i <= j; ++i)
        {
            int subSum = (i == 0) ? preSums[j] : preSums[j] - preSums[i-1]; // i - j 范围的 子数组的 和
            if (subSum == k) ans++;
        }
    }

    return ans;

}

/// 优化版：
/// 复杂度为O(n^2)的解法实际不可接受，我们来考虑优化方法
/// 既然有了前缀和，有没有一种O(n)，即一次遍历就能找到所有子数组的办法呢？
/// 既然要优化，就可以考虑空间换时间的策略，即记录下某些信息来避免嵌套的遍历查找
/// 这里引入一个重要洞察：对于每一个0 - j范围内的和为S + k的数组，在其之前只要存在和为S，范围为0 - i, (i < j)的数组，那么i - j区间的就是和为k的数组
/// 这个洞察的作用在于，我们可以记录这些和为S的数组的数量：
/// 假如遇到了和为S + k的数组，那么这时已经记录的 和为S的数组的数量 即为 这个和为S + k的数组 对应的 和为k的数组的数量
/// 为什么这个方法能成立？因为我们实际上无需知道这个子数组具体的索引区间，只需要数量，所以具体的i - j的范围信息是不需要的
/// 我们就可以直接建立 数组和 - 数量 的哈希映射来进行查找
/// 优化的点在哪？在于只需要一次遍历。我们可以只遍历j，通过S的存在性和数量（O(1)查找）来替代之前对i的遍历，得到(0 - j)，也就是和为S + k的数组对应的和为k的数组的数量
/// 最后回过头来看，暴力解法中，内层循环在做什么？
/// 它在查找：有多少个i满足preSum[i-1] = preSum[j] - k
/// 这就提示我们可以用哈希表来加速这个查找
/// 具体实现注意：
/// 1. 需要预处理一次前缀和为0，数量为1的映射，因为如果不处理的话，当 S + k 正好 == k 时，会因为map[0]不存在而跳过这次查找，缺失这个子数组的统计
/// 2. 前缀和的计算可以直接放入统计的逻辑中，减少一次O(n)的循环
/// 时间复杂度O(n)，空间复杂度O(n)

int Solve2(vector<int>& nums, int k)
{
    int preSum = 0;
    unordered_map <int, int> prefixSumCount = unordered_map <int, int>(); // 数组和 - 数量的映射

    int ans = 0;

    prefixSumCount[0] = 1; // 和为0 - 数量为1的映射

    for (int j = 0; j < nums.size(); ++j) // preSums[j]: 和为S + k的数组
    {
        preSum += nums[j]; // 直接在统计同时计算前缀和

        if (prefixSumCount.find(preSum - k) != prefixSumCount.end())
        {
            ans += prefixSumCount[preSum - k]; // 已经出现过的和为S，范围为0 - i, (i < j)的数组的数量
        }

        prefixSumCount[preSum]++; // 记录和为S的数组的数量
    }

    return ans;

}