#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

ll sum(ll st, ll en) {

    return (st + en) * (en - st + 1) / 2;

}


int main() {

    int time;
    cin >> time;

    for (; time; time--) {
        ll n, k;
        cin >> n >> k;

        ll ans = sum(k, k + n - 1);

        ll le = 0, ri = n - 1;

        while (ri >= le) {

            ll mid = (le + ri) / 2;

            if (sum(k, k + mid) - sum(k + mid + 1, k + n - 1) >= 0) {
                
                ans = sum(k, k + mid) - sum(k + mid + 1, k + n -1);
                ri = mid - 1;

            }

            else 
                le = mid + 1;

        } 

        le = 0; ri = n - 1;

        while (ri >= le) {

            ll mid = (le + ri) / 2;

            if (sum(k, k + mid) - sum(k + mid + 1, k + n - 1) <= 0) {

                ans = min(ans, abs(sum(k, k + mid) - sum(k + mid + 1, k + n - 1)));
                le = mid + 1;

            }

            else   
                ri = mid - 1;

        }

        cout << ans << endl;

    }
 
    return 0;
}