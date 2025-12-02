#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> arr(1005, 0);

signed main() {

    int T;
    cin >> T;

    while (T--) {
        
        fill(arr.begin(), arr.end(), 0);

        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {

            cin >> arr[i];

        }

        int mmax = *max_element(&arr[1], &arr[n] + 1);
        int mmin = *min_element(&arr[1], &arr[n] + 1);

        //cout << mmax << " " << mmin << endl;

        int ans = (n - 1) * (mmax - mmin);

        cout << ans << endl;

    }

    return 0;
}