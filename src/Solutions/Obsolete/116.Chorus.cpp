#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> arr(105, 0), dp_le(105, 1), dp_ri(105, 1);

signed main() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {

        cin >> arr[i];

    }

    int ans = 1000007;

    for (int mid = 1; mid <= n; mid++) {

        fill(dp_le.begin(), dp_le.end(), 1);
        fill(dp_ri.begin(), dp_ri.end(), 1);


        for (int i = 1; i < mid; i++) {
            for (int j = 1; j < i; j++) {

                if (arr[i] > arr[j]) {

                    dp_le[i] = max(dp_le[i], dp_le[j] + 1);

                }

            }

        }

        for (int i = n; i > mid; i--) {
            for (int j = n; j > i; j--) {

                if (arr[i] > arr[j]) {

                    dp_ri[i] = max(dp_ri[i], dp_ri[j] + 1);

                }

            }

        }

        int ans_le = *max_element(dp_le.begin(), dp_le.end());
        int ans_ri = *max_element(dp_ri.begin(), dp_ri.end());

        ans = min(ans, n - ans_le - ans_ri);

    }

    cout << ans << endl;

    return 0;
}