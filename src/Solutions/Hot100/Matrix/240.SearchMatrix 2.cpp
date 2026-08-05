#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

/// 思路类似二分，每次都确定性地排除一边，核心在于如何排除比较高效
/// 左上角的右边和下方都比自己大，不好排除
/// 观察右上角，左边这一行的元素都比自己小，下方这一列的元素都比自己大
/// 于是可以这样寻找：
/// 自己比target小，左边这一行都小，排除，row++
/// 自己比target大，下方这一行都大，排除，col--
/// 若相等就直接找到

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0, j = n - 1; i < m && j >= 0;)
        {
            if (matrix[i][j] < target) i++;
            else if (matrix[i][j] > target) j--;
            else return true;
        }

        return false;
    }
};