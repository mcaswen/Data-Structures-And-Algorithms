#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

signed main() {

    int Time;
    cin >> Time;
    
    for (int j = 1; j <= Time; j++) {

        int m, n;
        cin >> m >> n;

        ll ans = 0;
        for (int i = m; i <= n; i++) {

            ans += (ll)i * i * i;

        }

        cout << "Case #" << j << ": " << ans << endl;

    }

    return 0;

}