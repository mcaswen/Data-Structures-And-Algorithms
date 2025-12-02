#include <iostream>
#include <deque>
#include <vector>
#include <iomanip>

using namespace std;

vector < vector <int> > Map(405, vector <int> (405, -1)), visited(405, vector <int> (405, -1));
int dx[] = {1, 2, 1, -2, 2, -2, -1, -1};
int dy[] = {2, 1, -2, 1, -1, -1, 2, -2};

signed main() {

    int n, m, x, y;
    cin >> n >> m >> x >> y;

    deque < pair <int, int> > dq;

    dq.push_back(make_pair(x, y));
    Map[x][y] = 0;

    while (dq.size()) {

        int mx = dq.front().first;
        int my = dq.front().second;
        dq.pop_front();

        for (int i = 0; i < 8; i++) {

            int cx = mx + dx[i];
            int cy = my + dy[i];

            if (cx < 1 || cx > n || cy < 1 || cy > m || visited[cx][cy] != -1 || (cx == x && cy == y)) continue;

            Map[cx][cy] = Map[mx][my] + 1;
            visited[cx][cy] = 1;
            dq.push_back(make_pair(cx, cy));

        }

    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            cout << fixed  << setw(6) << Map[i][j];

        }
        
        cout << endl;

    }

    return 0;
}