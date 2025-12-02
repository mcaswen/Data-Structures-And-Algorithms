#include <iostream>
#include <algorithm>

using namespace std;

signed main() {

    int T;
    cin >> T;

    while (T--) {

        int m, n;
        cin >> m >> n;

        int mmax = max(m, n);
        int ans = mmax + 1;

        cout << ans << endl;

    }




    return 0;
}