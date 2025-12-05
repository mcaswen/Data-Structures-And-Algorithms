#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>
#include <unordered_map>

/// leetcode 1 两数之和
/// 要找到两个数的和，其实就是在数组对每个数都找另外一个加数，使其和为目标数
/// 先对数组排序，二分查找那个加数，注意索引是否等于自己的判断
/// 找到后返回正在查找的数和对应加数的索引即可

using namespace std;

int BinarySearch(vector < pair<int, int> >& nums, int num, int index, int n);
vector<int> Solve();

int main()
{
    vector<int> anss = Solve();

    if (!anss.empty())
        cout << anss[0] << " " << anss[1];
    else
        cout << "Not Found";
}

vector<int> Solve()
{
    vector <int> nums = vector <int>();
    vector< pair<int, int> > numsTemp = vector< pair<int, int> >();

    int n, target; cin >> n >> target;

    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        nums.push_back(num);
        numsTemp.push_back(make_pair(num, i));
    }
    vector<int> anss;

    sort(numsTemp.begin(), numsTemp.end(),
        [](const pair<int, int> a, const pair<int, int> b)
        {
            return a.first < b.first;
        }
    );

    for (int i = 0; i < n; ++i)
    {
        int num = target - numsTemp[i].first;
        int ans = BinarySearch(numsTemp, num, i, n);
        
        if (ans != -1)
        {
            anss.push_back(numsTemp[i].second);
            anss.push_back(ans);
            return anss;
        }
    }

    return anss;
}

int BinarySearch(vector < pair<int, int> >& nums, int num, int index, int n)
{
    int le = 0;
    int ri = n - 1;

    while (le <= ri)
    {
        int mid = le + (ri - le) / 2;

        // if (index == 0)
        // {
        //     cout << mid << " " << nums[mid] << " " << num << endl;
        // }

        if (nums[mid].first == num && mid != index)
        {
            return nums[mid].second;
        } 
        else if (nums[mid].first > num)
        {
            ri = mid - 1;
        } 
        else 
        {
            le = mid + 1;
        }
    }

    return -1;
}

/// 最优解法：哈希表（unordered_map）
/// 这个问题本质上是对于数组中的任意一个数i，另一个数j是否存在的问题。
/// 并且，两个数之间是对称的，既可以通过i找j，又可以通过j找i。
/// 然而，我们不能直接使用unordered_set来判断，因为数组中的元素可能索引不同但值相等，且set无法返回索引

/// 因此，使用unordered_map。对于每一个数，我们查找他对应的加数是否在表中存在：
    /// 若已存在，则这两个数构成一对答案
    /// 若不存在，则该数可能成为另一个数的加数，我们把它和索引存入哈希表

/// 由于对称性，所以遍历顺序无关紧要。
/// 可以保证遍历过程中，必然经历”i 先入表，通过 j 找到“ 或 “j 先入表，通过 i 找到”这两个过程之一
/// 时空复杂度 O(n)

vector<int> Solve2() {
    int n, target;
    cin >> n >> target;
    
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    unordered_map<int, int> numMap; // 存储<值, 索引>
    vector<int> result;
    
    for (int i = 0; i < n; ++i) {
        int complement = target - nums[i];
        
        // 检查补数是否在哈希表中
        if (numMap.find(complement) != numMap.end()) {
            result.push_back(numMap[complement]);
            result.push_back(i);
            return result;
        }
        
        // 将当前数和索引存入哈希表
        numMap[nums[i]] = i;
    }
    
    return result;
}