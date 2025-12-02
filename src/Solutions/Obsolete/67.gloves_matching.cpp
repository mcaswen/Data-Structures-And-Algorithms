#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector < vector <ll> > cnum(2010, vector<ll>(2010, 0));
ll mod = 1e9 + 7;

bool isvalid = true;

void getc() {

    for (int i = 0; i <= 2005; i++) {
        
        cnum[i][0] = 1;
        cnum[i][i] = 1;

    }

    for (int i = 1; i <= 2005; i++) {
        for (int j = 1; j <= i; j++) {
            
            cnum[i][j] = (cnum[i-1][j] + cnum[i-1][j-1] ) % mod;
        
        }
    }
}

ll quickpow(ll a, ll b) {

    ll ans = 1;

    while (b > 0) {
        if ( b % 2 ) {
           
            ans = ans * a % mod;

        }

        a = a * a % mod;
        b /= 2;

    }

    return ans;

}

ll c(ll m, ll n) {

    if (n > m || n < 0) {
        
        isvalid = false;
        return 0;
    
    }

    else 
        return cnum[m][n];


}


int main() {

    getc();

    int t;int ac;
    cin >> t;

    for (; t; t--) {    
        
        int n, m, k;
        isvalid = true;

        cin >> n >> m >> k;

        ll ans = c(n, k) % mod;
        ans = ans * c(n - k, m - 2 * k) % mod;
        ans = ans * quickpow(2, m - 2 * k) % mod;
        
        if (isvalid && m - 2 * k <= 2 * (n - k))
            cout << ans << endl;
    
        else 
            cout << 0 << endl;

    }
    
    return 0;
}