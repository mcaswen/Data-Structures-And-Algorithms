#include <iostream>
#include <utility>
#include <vector>
#include <deque>

/// 滑动窗口最大值，经典问题
/// 一般维护最大值问题，我们会想到优先队列，堆等
/// 但是这道题中，窗口本身在不断变化，如果使用这种O(logn)取元素的数据结构，索引的维护成了问题
/// 每次窗口更新都要遍历并找出过期索引，这个时间复杂度是不可接受的
/// 于是，我们要想出一种仅凭双向队列的出入队操作就能找出最大值的办法
/// 可以联想到双向队列的性质，有队头和队尾供查询
/// 因为要更新滑动窗口，所以队尾一般用于新元素的入队，我们要在队头上做文章
/// 即保持队头总为滑动窗口的最大值，这样查询时就是O(1)的复杂度
/// 那么，如何保证这一点呢？
/// 也就是说，队尾进入的元素，假如它大，就要让它尽可能往前移动，使它成为潜在的最大值
/// 那么，非常朴素的思想就是，和队尾元素不断比较，如果大于等于队尾元素，就向前移动，即弹出队尾元素
/// 这个弹出操作也不会丢失可能的最大值，因为新元素一定比队尾大，或者索引比队尾新，队尾就不再可能成为最大值了
/// 如果遇到了比自己大的队尾元素，因为这个队尾元素可能会在之后的更新中过时，新元素还有可能成为最大值，于是入队
/// 那么更新过程就很清晰了，先更新窗口队头，弹出过期元素（用pair存元素-索引映射）
/// 再执行上面提到的维护最大值操作，每次窗口更新结束后将当前窗口最大值（即队头）加入答案数组即可
/// 这也就是单调队列的维护，这里是单调递减队列
/// 时间复杂度O(n), 空间复杂度O(k)
/// 实现过程中注意两点，一是清理过期队头时注意检查窗口是否为空，否则索引检查会抛异常
/// 二是构建窗口的逻辑不用单独写，根据i 是否 >= k - 1 即可判断窗口是否构建完毕，构建完毕后才开始更新答案（最大值）


using namespace std;

vector<int> Solve(vector<int>& nums, int k);

vector <int> ans;
vector <int> nums;

int main()
{
    int n, k; cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {   
        int num; cin >> num;
        nums.push_back(num);
    }

    ans = Solve(nums, k);

    for (auto num: ans)
    {
        cout << num << " ";
    }

}

vector<int> Solve(vector<int>& nums, int k)
{
    vector <int> ans = vector <int>();
    deque <pair <int, int> > window = deque <pair<int, int> >();

    int n = nums.size();

    for(int i = 0; i < n; ++i)
    {
        while (!window.empty() && window.front().second <= i - k) // 注意队列为空的检查, i - k 之前的为过期索引
        {
            window.pop_front();
        }

        while(!window.empty())
        {
            int tail = window.back().first; //取出队尾
            if (nums[i] >= tail) // 等于时也弹出，因为新元素索引更大，更不容易过期
            {
                window.pop_back(); // 比较并弹出
            } 
            else break;
        }

        window.push_back(make_pair(nums[i], i));
        
        // 简化代码，构建窗口时无需重复逻辑，根据索引，仅在窗口构建完毕后记录答案
        if (i >= k - 1) 
            ans.push_back(window.front().first); 
    }

    return ans;
}

// 8 3
// 1 3 -1 -3 5 3 6 7