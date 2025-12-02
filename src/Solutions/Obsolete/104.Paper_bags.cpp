#include <iostream>
#include <vector>

using namespace std;

vector <char> arr(200005, 0);

signed main() {

    int T;
    cin >> T;

    while (T--) {

        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++) {

            cin >> arr[i];

        }

        long long ans = 0;

        for (int i = 1; i <= n; ) {

            if (arr[i] == 'B') {

                i += k;

                ans++;

            } else i++;

        }

        cout << ans << endl;
    
    }
    
    return 0;
}