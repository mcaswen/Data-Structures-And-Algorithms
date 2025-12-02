#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector <vector <char> > visited(150, vector <char>(150, 0)), Map(150, vector <char>(150, 0));
deque <pair <int, int> > dq;
int M, N;
bool isfound = false;


void dfs(int x, int y) {

    if (Map[x][y] == '*' || visited[x][y]) return;
    if (isfound) return;

    visited[x][y] = 1;
    dq.push_back(make_pair(x, y));

    if (x == M && y == N) {

        for (auto p: dq) {

            cout << p.first << " " << p.second << '\n';

        }
        
        isfound = true;
        exit(0);
        return;

    }

    if (y > 1) dfs(x, y-1);
    if (y < N) dfs(x, y+1);
    if (x > 1) dfs(x-1, y);
    if (x < M) dfs(x+1, y);

    //visited[x][y] = 0;
    dq.pop_back();

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N;  

    cin.ignore();

    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++) {

            cin >> Map[i][j];

        }

    dfs(1,1);

    return 0;
}