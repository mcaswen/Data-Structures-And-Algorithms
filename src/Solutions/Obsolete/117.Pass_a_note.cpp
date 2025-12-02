#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
vector <vector <int> > MAP(55, vector <int>(55, 0)), dp(55, vector <int>(55, -1));
deque <int> dq_max;

int m, n;

int dfs(int x, int y, bool reached) {

    //if (reached && x == 1 && y == 1) {

        cout << x << " " << y << endl;

    //}   



    if (dp[x][y] != -1) {
       // cout << "return" << endl;
        return dp[x][y];
    
    }

    if (reached) {

        if (x == 1 && y == 1) {
            
            return dp[1][1];

        }

    } 

    //cout << "op" << endl;

    int maxvalue = 0;

    if (x > 1) maxvalue =  max(maxvalue, dfs(x-1, y, reached || (x == m && y == n)));
    if (y > 1) maxvalue =  max(maxvalue, dfs(x, y-1, reached || (x == m && y == n)));
    if (x < m) maxvalue =  max(maxvalue, dfs(x+1, y, reached || (x == m && y == n)));
    if (y < n) maxvalue =  max(maxvalue, dfs(x, y+1, reached || (x == m && y == n)));

    dp[x][y] = MAP[x][y] + maxvalue;

    return dp[x][y];

}

signed main() {

    cin >> m >> n;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) 
            cin >> MAP[i][j];

    bool reached = false;

    int ans = dfs(1, 1, reached);

    cout << ans << endl;

    return 0;
}