#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

/// 本道题中，要用顺时针螺旋遍历矩阵
/// 如果硬用循环嵌套的话，边界条件十分复杂
/// 一个关键洞察是，可以把每次矩阵的最外围一周的遍历看作一次递归
/// 即从 (0, 0) 到 (0, m) ，到 (n, m) ，再到 (n, 0) ，最后到 (0, 0) 
/// 每次遍历完一周后，我们实际上会进入一个左上角为 (k, k) ，右下角为 (n - k, m - k) 的嵌套矩阵（k为已递归的次数）
/// 然后再用相同方式遍历该矩阵的外围即可
/// 另一个重点在边界条件处理
/// 由于每次递归，矩阵的长和宽都会减2，所以停止遍历的条件是 n - 2k <= 0 || m - 2k <= 0
/// 然而 n - 2k == 1 || m - 2k == 1 的单行/列情况要特殊讨论，因为他和最外围一周的遍历方式不同
/// 当 n - 2k == 1 ，即嵌套矩阵只剩1行，那么只需从(k, k)开始遍历到 (k, m - k) 即可
/// 同理，当 m - 2k == 1 ，即嵌套矩阵只剩1列，那么只需从 (k, k) 开始遍历到 (n - k, m) 即可
/// 实现时注意：
/// 1. 对于 (i, m - k) 或者 (n - k, i) 位置，使用 matrix[i][m - k] 或者 matrix[n - k][i] 会发生索引越界，要用 m - k - 1 和 n - k - 1
/// 2. 在剩下三次循环中，起点要多移动一位，否则会重复遍历起点一次

using namespace std;

vector<int> Solve(vector<vector<int>>& matrix, int n, int m);
void TraverseOuter(vector<vector<int>>& matrix, vector<int>& ans, int n, int m, int k);

int main()
{
    vector<vector<int>> matrix(100, vector<int>(100, 0));

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            cin >> matrix[i][j];
        }

    auto ans = Solve(matrix, n, m);
    
    for (auto num: ans)
        cout << num << " ";

}

vector<int> Solve(vector<vector<int>>& matrix, int n, int m)
{
    vector<int> ans = vector<int>();

    TraverseOuter(matrix, ans, n, m, 0);

    return ans;
}

void TraverseOuter(vector<vector<int>>& matrix, vector<int>& ans, int n, int m, int k)
{
    if (n - 2 * k <= 0 || m - 2 * k <= 0) return; // 遍历完毕
    
    if (n - 2 * k == 1) // 剩单行
    {
        for (int i = k; i < m - k; ++i)
        {
            ans.push_back(matrix[k][i]); 
        }

        return;
    }

    else if (m - 2 * k == 1) // 剩单列
    {
        for (int i = k; i < n - k; ++i) 
        {
            ans.push_back(matrix[i][k]); 
        }

        return;
    }

    else // 正常遍历一周
    {
        for (int i = k; i < m - k; ++i) // (k, k) -> (k, m - k)
        {
            ans.push_back(matrix[k][i]);
        }

        for (int i = k + 1; i < n - k; ++i) // (k, m - k) -> (n - k, m - k)
        {
            ans.push_back(matrix[i][m - k - 1]);
        }

        for (int i = m - k - 2; i >= k; --i) // (n - k, m - k) -> (n - k, k)
        {
            ans.push_back(matrix[n - k - 1][i]);
        }

        for (int i = n - k - 2; i >= k + 1; --i) // (n - k, k) -> (k + 1, k)
        {
            ans.push_back(matrix[i][k]);
        }
    }

    TraverseOuter(matrix, ans, n, m, k + 1);
}

// 3 3
// 1 2 3 4 5 6 7 8 9