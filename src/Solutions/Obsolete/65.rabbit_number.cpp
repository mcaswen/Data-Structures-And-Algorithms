#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main() {

    ll m, n;
    cin >> m >> n;

    ll cntans = 0;

    for (ll i = m; i <= n;) {
        
        ll sumx = 0, sumxx = 0, islegal = 1, num = i;
        
        ll al = 1;
        int cnt = 0;
        
        while (num > 0) {
            
            ll temp = num % 10;
            cnt++;
            al *= 10;
            
            if (i / (al / 10) % 10 > 3) {
                i += al - i % al;
                islegal = 0;
                break;
            
            }

            sumx += temp;     

            num /= 10;

        }

        if (!islegal)
            continue;
            
            ll pownum = i * i;

            while (pownum > 0) {
            
                ll temp = pownum % 10;

                //cout << temp << endl;

                sumxx += temp;     

                pownum /= 10;

            }

            if (sumx != 0 && sumx * sumx == sumxx)
                cntans++;
    
            
            i++;
    
    }

    cout << cntans << endl;

    return 0;
}