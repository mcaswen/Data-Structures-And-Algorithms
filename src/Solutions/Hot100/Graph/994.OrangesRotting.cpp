#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

/// BFS 看所有烂橘子传播次数的最大值
/// 具体怎么看：不能对每个单独橘子计数，而是看传播波形。对所有烂橘子标记1,然后每个橘子传播到的橘子都打上该橘子的计数+1
/// 这样标记最大值 -1 就是所有烂橘子需要的传播次数
/// 扩张完之后再扫一遍看看有没有剩的橘子，有就返回-1
/// 注意多个烂橘子可能在一个岛屿同时更新，所以要做多源bfs，先收集所有橘子放进同一个 dq，同时更新即可

class Solution {
public:

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    vector<vector<int>> isVisited;

    int orangesRotting(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        isVisited = vector(m, vector<int>(n, 0));
        deque<pair<int, int>> dq;

        // 所有烂橘子统一入队
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
        {
            if (grid[i][j] != 2) continue;
            dq.push_back(make_pair(i, j));
            isVisited[i][j] = 1;
        }

        // 烂橘子不在一个岛屿也不影响，多源 bfs 有最近源性质
        while (!dq.empty())
            {
                auto [i, j] = dq.front();
                dq.pop_front();

                for (int k = 0; k < 4; ++k)
                {
                    int ki = i + dx[k];
                    int kj = j + dy[k];

                    if (ki < 0 || kj < 0 || ki >= m || kj >= n || isVisited[ki][kj] != 0 || grid[ki][kj] != 1) continue;

                    grid[ki][kj] = 2;
                    isVisited[ki][kj] = isVisited[i][j] + 1;
                    dq.push_back(make_pair(ki, kj));
                    ans = max(ans, isVisited[ki][kj] - 1); // 本质计算新鲜橘子距离腐烂源的最短距离
                }
            }
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
        {
            if (grid[i][j] == 1) return -1;
        }

        return ans;
    }

};

