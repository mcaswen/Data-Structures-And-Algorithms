#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector <ll> a(1005, 0), b(1005, 0), c(1005, 0), d(1005, 0), ans;

ll min1(ll a, ll b) {

    return a < b ? a : b;

}



signed main() {

    int T;
    cin >> T;

    while (T--) {

        int n, k;
        cin >> n >> k;

        vector<ll> pre_dp(k + 1, 1e9), cur_dp(k + 1, 1e9);

        pre_dp[0] = 0;

        for (int i = 1; i <= n; i++) {

            cin >> a[i] >> b[i] >> c[i] >> d[i];

            for (int j = 0; j <= k; j++) {
                
                cur_dp[j] = pre_dp[j];

                if (j >= 1) cur_dp[j] = min1(cur_dp[j], pre_dp[j - 1] + a[i]);
                if (j >= 2) cur_dp[j] = min1(cur_dp[j], pre_dp[j - 2] + b[i]);
                if (j >= 3) cur_dp[j] = min1(cur_dp[j], pre_dp[j - 3] + c[i]);
                if (j >= 4) cur_dp[j] = min1(cur_dp[j], pre_dp[j - 4] + d[i]);

                pre_dp = cur_dp;

            }

        }

        cout << cur_dp[k] << endl;

    }

    return 0;
}