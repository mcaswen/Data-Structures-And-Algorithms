#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> arr(5005, 0);
vector <int> dp(5005, 1);

signed main() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {

        cin >> arr[i];

        for (int j = 1; j < i; j++) {

            if (arr[j] < arr[i]) {

                dp[i] = max(dp[i], dp[j] + 1);
            
            }

        }

    }

    int ans = *max_element(dp.begin(), dp.end());

    cout << ans << endl;

    return 0;
}