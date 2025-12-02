//leetcode 827
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

unordered_map <int, int> mark;

int id = 2;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {

    if (i < 0 || i == n || j < 0 || j == m || grid[i][j] != 1) return;

    grid[i][j] = id;
    mark[id]++;

    for (int k = 0; k < 4; k++) {

        dfs(grid, i + dx[k], j + dy[k], n, m);

    }

}

int largestIsland(vector<vector<int>>& grid) {
    
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {

            if (grid[i][j] == 1) {

                dfs(grid, i, j, n, m);
                id++;

            }

        }
    
    int ans = 0;

    for (int i = 0; i < n; i++)   
        for (int j = 0; j < m; j++) {

            if (grid[i][j] == 0) {

                int sum = 1;
                unordered_set <int> st;
                for (int k = 0; k < 4; k++) {

                    int curx = i + dx[k];
                    int cury = j + dy[k];
                    
                    if (curx == -1 || curx == n || cury == -1 || cury == m || grid[curx][cury] < 2)
                        continue;

                    st.insert(grid[i + dx[k]][j + dy[k]]);

                }

                for (auto p: st) {

                    sum += mark[p];

                }

                ans = max(sum, ans);

            }

        }

    return ans;

}