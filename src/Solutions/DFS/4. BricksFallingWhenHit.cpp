//leetcode 803
#include <vector>
#include <stack>

using namespace std;

int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};
stack <int> sk;

void CelDfs(vector <vector <int>>& grid, int i, int j, int n, int m) {

    if (i < 0 || i == n || j < 0 || j == m || grid[i][j] != 1)
        return;

    grid[i][j] = 2;

    for (int k = 0; k < 4; k++) {

        CelDfs(grid, i + dx[k], j + dy[k], n, m);

    }
    
}

void HitDfs(vector <vector <int>>& grid, int i, int j, int n, int m, int& cnt) {

    if (i < 0 || i == n || j < 0 || j == m || grid[i][j] != 1)
        return;


    grid[i][j] = 2;
    cnt++;

    for (int k = 0; k < 4; k++) {

        HitDfs(grid, i + dx[k], j + dy[k], n, m, cnt);

    }

}

vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {

    int siz = hits.size();

    for (int i = 0; i < siz; i++) {

        int x = hits[i][0];
        int y = hits[i][1];

        grid[x][y] = (grid[x][y] == 1) ? 0 : -1;

    }

    int n = grid.size();
    int m = grid[0].size();

    vector <int> ans2;

    if (n == 1) return ans2;

    for (int j = 0; j < m; j++) {

        CelDfs(grid, 0, j, n, m);

    }

    for (int i = siz - 1; i >= 0; i--) {

        int x = hits[i][0];
        int y = hits[i][1];

        grid[x][y]++;

        if (grid[x][y] == 0) { sk.push(0); continue;}

        if (x == 0 || (y > 0 && grid[x][y-1] == 2) ||  (y < m - 1 && grid[x][y+1] == 2) ||  (x > 0 && grid[x-1][y] == 2) || (x < n - 1 && grid[x+1][y] == 2)) {

            int cnt = 0;
            HitDfs(grid, x, y, n, m, cnt);
            sk.push(cnt - 1);

        } else {

            sk.push(0);

        }

    }

    vector <int> ans;

    while (!sk.empty()) {

        ans.push_back(sk.top());
        sk.pop();

    }

    return ans;

}