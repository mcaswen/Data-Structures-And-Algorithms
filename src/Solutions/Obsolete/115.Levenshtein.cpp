#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector <int> > dp(2005, vector <int>(2005, 1e6));

signed main() {

    string a, b;
    cin >> a >> b;

    int a_size = a.size();
    int b_size = b.size();

    for (int i = 0; i < a_size; i++)
        dp[i][0] = i;

    for (int j = 0; j < b_size; j++) 
        dp[0][j] = j;

    for (int i = 1; i <= a_size; i++) {
        for (int j = 1; j <= b_size; j++) {

            if (a[i-1] == b[j-1]) {

                dp[i][j] = dp[i-1][j-1];

            } else {

                dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
                dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
                dp[i][j] = min(dp[i][j], dp[i][j-1]+1);

            }

        }

    }

    cout << dp[a_size][b_size] << endl;

    return 0;
}