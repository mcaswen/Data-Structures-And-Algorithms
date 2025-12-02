#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

vector <int> value(1005, 0), tim(1005, 0), dp(1005, 0);

signed main() {

    int T, M;
    cin >> T >> M;

    for (int i = 1; i <= M; i++) {

        cin >> tim[i] >> value[i];

        for (int j = T; j >= tim[i]; j--) {

            dp[j] = max(dp[j], dp[j-tim[i]] + value[i]);

        }

    }

    cout << dp[T] << endl;

    return 0;
}