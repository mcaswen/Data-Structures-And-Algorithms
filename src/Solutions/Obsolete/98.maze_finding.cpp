#include <iostream>
#include <vector>

using namespace std;

vector < vector <char> > Map(105, vector <char>(105, 0)), visited(105, vector <char>(105, 0));
bool isfound = false;
int n, m;

void dfs(int x, int y) {

    if (Map[x][y] == '#' || visited[x][y]) return;

    visited[x][y] = 1;

    if (x == n && y == m) {

        isfound = true;
        cout << "Yes" << endl;
        return;
    
    }



    if (x > 1) dfs(x-1, y);
    if (x < n) dfs(x+1, y);
    if (y > 1) dfs(x, y-1);
    if (y < m) dfs(x, y+1);

}

signed main() {

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {

            cin >> Map[i][j];

        }

        dfs(1, 1);

        if (!isfound) cout << "No" << endl;

    return 0;

}