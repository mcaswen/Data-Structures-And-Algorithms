#include <iostream>

using namespace std;
typedef long long ll;
ll mod = 100003;

ll quickpow(ll a, ll b) {

    ll ans = 1;

    while (b > 0) {
        if (b % 2) {

            ans *= a;
            ans %= mod;

        }

        a *= a;
        a %= mod;
        b /= 2;

    }

    return ans;

}


int main() {

    ll m, n;
    cin >> m >> n;

    ll ans = (quickpow(m, n) - (m * quickpow(m - 1, n - 1)) % mod + mod) % mod;

    cout << ans << endl;

    return 0;
}