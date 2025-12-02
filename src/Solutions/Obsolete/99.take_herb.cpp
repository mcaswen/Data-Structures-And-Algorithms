#include <iostream>
#include <vector>

using namespace std;

vector <pair <int, int> >  herb(1005, {0, 0});
vector < vector <int> > mem(1005, vector <int>(1005, -1));
int T, M;

int max(int a, int b) {

    return a > b ? a : b;

}

int dfs(int t, int x) {

    if (mem[t][x] != -1)
        return mem[t][x];

    if (x == 0 || t == 0) 
        mem[t][x] = 0;

    if (herb[x].first > t) {

        mem[t][x] = dfs(t, x-1);

    } else {

        mem[t][x] = max(dfs(t, x-1) , dfs(t-herb[x].first, x-1) + herb[x].second);

    }

    return mem[t][x];

}

signed main() {

    cin >> T >> M;

    for (int i = 1; i <= M; i++) {

        cin >> herb[i].first >> herb[i].second;

    }

    cout << dfs(T, M) << endl;

    return 0;
}