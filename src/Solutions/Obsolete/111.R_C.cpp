#include <iostream>
#include <unordered_set>

using namespace std;

typedef long long ll;
unordered_set <ll> s;


ll solve(ll n, ll num) {

    ll sum = 0;

    for (int i = 1; num * i <= n; i++) {
        
        if (s.find(i * num) == s.end()) {
            
            s.insert(i * num);
            sum++;

        } 
    
    }

    return sum;

}

signed main() {

    ll n;
    cin >> n;

    ll a, b, c , d;
    cin >> a >> b >> c >> d;

    int ans = 0;
    ans += solve(n, a);
    ans += solve(n, b);
    ans += solve(n, c);
    ans += solve(n, d);

    cout << ans << endl;

    return 0;
}