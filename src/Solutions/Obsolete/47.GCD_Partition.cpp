#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector <ll> arr(200010, 0);

ll gcd (ll x, ll y) {
    
    return y ? gcd(y , x % y) : x;

}

int main() {
    int t;
    int tim; cin >> tim;

    for (; tim; tim--) {
        int n; cin >> n;       
        ll sum = 0;
        
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            sum += arr[i];

        }
        ll cur = 0;
        ll ans = 1;
        for (int i = 1; i < n; i++) {
            
            cur += arr[i];
            sum -= arr[i];
            ans = max(ans, gcd(cur, sum));

        }

        cout << ans << endl;

    }

    return 0;
}