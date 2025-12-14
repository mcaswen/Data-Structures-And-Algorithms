#include <algorithm>
#include <vector>

using namespace std;

// 选择排序
void SelectSort(vector <int>& nums)
{
    if (nums.empty() || nums.size() < 2) return; // 空检查

    for (int minIndex, i = 0; i < nums.size(); ++i)
    {
        // i: 0 - i 范围视为当前已经排序完毕的范围
        // minIndex: 当前除去已排序范围内的所有数中的最小值的索引
        
        minIndex = i; // 从i位置开始寻找，若“临时最小值”为自身则交换自身
        
        for (int j = minIndex + 1; j < nums.size(); ++i) // 在剩余范围内寻找最小值
        {
            if (nums[j] < nums[minIndex])
            {
                minIndex = j; // 若找到更小值更新索引
            }
        }
        // 内层循环结束后，保证 i ~ n - 1 范围内的最小值索引被找到

        swap(nums[i], nums[minIndex]); // 将找到的“临时最小值”与当前要拓展的已排序边界交换
    }
}

// 冒泡排序
void BubbleSort(vector <int>& nums)
{
    if (nums.empty() || nums.size() < 2) return; // 空检查

    for (int i = nums.size() - 1; i > 0; --i) // i: i ~ n - 1 范围视为已经排序完毕的范围
    {
        for (int j = 0; j < i; ++j) // 从 0 开始到 i - 1， 不断将更大的元素向后移动
        {
            if (nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]); // 后移一位更大元素
        }
        // 内层循环结束后，保证 0 ~ i - 1 范围内的最大元素被移动至i位置
    }
}

// 插入排序
void InsertSort(vector <int>& nums)
{
    if (nums.empty() || nums.size() < 2) return; // 空检查

    for (int i = 0; i < nums.size() - 1; ++i) // i: 0 ~ i 范围视为已经排序完毕的范围
    {
        for (int j = i + 1; j > 0 && nums[j] < nums[j - 1]; j--) // j: 要插入的元素的索引
        {
            swap(nums[j], nums[j - 1]); // 通过不断向前交换，保证 i + 1 位置元素插入到正确的有序位置
        }
        // 内层循环结束后，保证 0 ~ i + 1 范围有序
    }
}
