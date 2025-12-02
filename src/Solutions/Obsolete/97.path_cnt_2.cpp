#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector < vector<int> > Map(1005, vector<int>(1005, 0)), visited(1005, vector<int>(1005, 0));
int M, N;

int dfs(int x, int y) {

    if (x == M && y == M) return 1;

    if (x < 1 || y < 1 || x > M || y > M || Map[x][y] == -1) return 0;
    if (visited[x][y]) return Map[x][y];

    visited[x][y] = 1;
    Map[x][y] = (dfs(x+1, y) + dfs(x, y+1)) % 100003;
    
    //cout << x << " " << y << " " << Map[x][y] << endl;

   return Map[x][y];

}

signed main() {

    cin >> M >> N;

    while (N--) {

        int x, y;
        cin >> x >> y;
        Map[x][y] = -1;

    }

    cout << dfs(1, 1) << endl;

    return 0;

}