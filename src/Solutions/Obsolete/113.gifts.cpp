#include <iostream>
#include <unordered_set>
using namespace std;

typedef long long ll;
#define MOD 100007



ll mod_pow(ll a, ll b) {

    ll res = 1;
    
    while (b > 0) {

        if (b & 1) {

            res = (res * a) % MOD;

        } 

        a = (a * a) % MOD;
        b /= 2;

    }

    return res;

}




signed main() {


    int n;
    cin >> n;

    unordered_set <int> s;

    for (int i = 1; i <= n; i++) {

        int num;
        cin >> num;
        s.insert(num);

    }

    int num = s.size();

    ll mi = mod_pow(2, num);

    ll ans = 0;

    ll mi2 = mi / 2;

    for (int i = 1; i <= num; i++) {

        ans = (ans + (mi2 - 1)) % MOD;

    }

    //cout << mi << endl;

    ans = (ans - (mi - 1 - num + MOD) + MOD) % MOD;

    cout << ans << endl;

    return 0;
}