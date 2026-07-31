#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

/// 核心思想：联想到环状匹配机制，因为所有数字都要移动到固定位数之后。最容易联想到直接把数字和要移动到的位置交换，并记录那个位置上的数字作为下一次交换的前置
/// 如果没有多环，那么当cur再次移动到原点时说明交换完毕
/// 后续实现中发现可能遇到cur再次移动到原点，但还有元素没被交换的情况
/// 定位到这是size和k不互质导致多环，于是想到一个思路是先不断右移1，直到k和size互质也就是只剩一个环，然后再右移k
/// 但正解应该是，分别处理多个环。
/// 起点不再只有0，而是从0开始遍历，start从0，1，2，3开始处理环，每次cur == start就跳转到下一个环
/// 同时记录已经处理的数字数量，如果数量==size就停止，这样保证On处理完所有环


class Solution1 {
public:

    int gcd(int a, int b)
    {
        if (b == 0) return a;

        return gcd(b, a % b);
    }

    void rotate(vector<int>& nums, int k) 
    {
        while (k != 0 && gcd(nums.size(), k) == 1)
        {
            int cur = 0;
            int next = (1 + nums.size()) % nums.size();;
            int curNum = nums[cur];
            int nextNum = nums[next];

            k--;
            do
            {
                nums[next] = curNum;
                
                cur = next;
                next = (next + 1 + nums.size()) % nums.size();

                curNum = nextNum;
                nextNum = nums[next];

            } while (cur != 0);
        }
        
        int cur = 0;
        int next = (k + nums.size()) % nums.size();;
        int curNum = nums[cur];
        int nextNum = nums[next];

        do
        {
            nums[next] = curNum;
            
            cur = next;
            next = (next + k + nums.size()) % nums.size();

            curNum = nextNum;
            nextNum = nums[next];

            for (auto i: nums)
            {
                cout << i;
            }
            cout << endl;

        } while (k != 0 && cur != 0);
    }
};

class Solution2 {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int dealedNums = 0;
        for (int start = 0; start < nums.size() && dealedNums != nums.size(); start++)
        {
            int cur = start;
            int next = (start + k + nums.size()) % nums.size();;
            int curNum = nums[cur];
            int nextNum = nums[next];
            do
            {
                nums[next] = curNum;
                dealedNums++;

                cur = next;
                next = (next + k + nums.size()) % nums.size();

                curNum = nextNum;
                nextNum = nums[next];

            } while (cur != start);
        }
    }
};