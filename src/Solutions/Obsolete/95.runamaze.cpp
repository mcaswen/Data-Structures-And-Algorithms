#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector < vector <int> > Map(20, vector<int>(20, 0)), visited(20, vector<int>(20, 0));
deque <pair <int, int> > dq;
int end_x, end_y, st_x, st_y, M, N;
bool isfound = false;

void dfs(int x, int y) {

    if (Map[x][y] == 0 || visited[x][y] == 1) return;

    visited[x][y] = 1;
    dq.push_back(make_pair(x, y));

    if (x == end_x && y == end_y) {
        isfound = true;

        for (auto p: dq) {
            if (p == dq.back()) {

                cout << "(" << p.first << "," << p.second << ")";

            } else {

                cout << "(" << p.first << "," << p.second << ")->";

            }

        }

        cout << endl;

    } 
    if (y > 1) dfs(x, y-1);
    if (x > 1) dfs(x-1, y);
    if (y < N) dfs(x, y+1);
    if (x < M) dfs(x+1, y);
    
    visited[x][y] = 0;
    dq.pop_back();
    
}


signed main() {

    cin >> M >> N;

    for (int i = 1; i <= M; i++) 
        for (int j = 1; j <= N; j++) {

            cin >> Map[i][j];

        }
        cin >> st_x >> st_y >> end_x >> end_y;

        dfs(st_x, st_y);

    if (!isfound) cout << -1 << endl;

    return 0;

}