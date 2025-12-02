#include <iostream>
#include <deque>

using namespace std;

int Map[10][10];
int visited[10][10];
deque < pair <int, int> > dq;
int end_x, end_y;
bool isfound = false;

int dfs(int x, int y) {

    if (isfound) return;
    if (Map[x][y] == 0 || visited[x][y] == 1) return;

    if (x == end_x && y == end_y) {

        for (auto p: dq) {

            cout << p.first << " " << p.second << endl;

        }
        
        isfound = true;
        return;

    }

    visited[x][y] = 1;
    dq.push_back(make_pair(x, y));

    if (x >= 1) dfs(x-1, y);
    if (x < 9) dfs(x+1, y);
    if (y >= 1) dfs(x, y-1);
    if (y < 9) dfs(x, y+1);

    visited[x][y] = 0;
    dq.pop_back();

}