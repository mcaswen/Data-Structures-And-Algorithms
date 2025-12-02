#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n, P, l ,t;
    
bool check(ll num) {

    num = n - num;

    return num * l + min(2 * num, (n - 1) / 7 + 1) * t >= P;

}

int main() {

    int time;
    cin >> time;
    
    
    for (; time; time--) {

        cin >> n >> P >> l >> t;

        ll day = 0;
        
        ll ri = n; ll le = 0;

        while (ri >= le) {

            ll mid = (ri + le) / 2;

            if (check(mid)) {
                
                day = mid;
                le = mid + 1;
                            
            }
            else
                ri = mid - 1;

        }
        
    cout << day << endl;

    }

    return 0;
}