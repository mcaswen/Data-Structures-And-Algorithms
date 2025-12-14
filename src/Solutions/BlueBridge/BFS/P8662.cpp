#include <iostream>
#include <deque>
#include <utility>

int up[4] = {0, 1, 0, -1};
int down[4] = {-1, 0, 1, 0};

using namespace std;

bool checkIfNearSea(int i, int j);
bool BFS(int i, int j);

char map[1001][1001];
bool isBFSed[1001][1001] = {false};

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
        cin.get();
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == '#' && !isBFSed[i][j])
            {
                if (BFS(i, j)) ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}

bool BFS(int i, int j)
{
    deque <pair <int, int>> dq;
    bool isDrunk = true;

    dq.push_back(make_pair(i, j));
    isBFSed[i][j] = true;
    if (!checkIfNearSea(i, j)) isDrunk = false;

    while (!dq.empty())
    {
        auto [x, y] = dq.front();
        dq.pop_front();

        for (int k = 0; k < 4; k++)
        {
            int ci = x + up[k];
            int cj = y + down[k];

            if (map[ci][cj] == '#' && !isBFSed[ci][cj])
            {
                dq.push_back(make_pair(ci, cj));
                isBFSed[ci][cj] = true;
                if (!checkIfNearSea(ci, cj)) isDrunk = false;
            }
        }
    }

    return isDrunk;
}

bool checkIfNearSea(int i, int j)
{
    for (int k = 0; k < 4; k++)
    {
        char c = map[i + up[k]][j + down[k]];
        if (c == '.') return true;
    }

    return false;
}