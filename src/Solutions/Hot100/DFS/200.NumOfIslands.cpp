#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

/// 本道题中，求岛屿数量，经典的dfs题
/// 对于每个岛屿，即遇到'1'时，答案++，并且把整个岛屿打上特殊标记，比如'2'
/// 即用递归方法找寻上下左右四个方向的'1'，若找到就标记成'2'，并开始下一轮递归，若没找到（碰到边界或不为'1'）就返回
/// 时空复杂度O(m * n)

using namespace std;

int Solve(vector<vector<char>>& grid);
void dfs(vector<vector<char>>& grid, int n, int m, int i, int j);

int main()
{
    vector<vector<char>> grid(100, vector <char>(100, '0'));
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];
    
    cout << Solve(grid) << endl;

}

int Solve(vector<vector<char>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int ans = 0;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == '1')
            {
                ans++;
                dfs(grid, n, m, i, j);
            }

        }

    return ans;
}

void dfs(vector<vector<char>>& grid, int n, int m, int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != '1') return; // 不满足条件，碰了边界/不是未探索的岛屿区域

    grid[i][j] = '2';

    dfs(grid, n, m, i + 1, j); // 下
    dfs(grid, n, m, i - 1, j); // 上
    dfs(grid, n, m, i, j + 1); // 右
    dfs(grid, n, m, i, j - 1); // 左
}


