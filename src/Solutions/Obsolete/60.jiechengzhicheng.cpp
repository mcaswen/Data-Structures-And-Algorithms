#include <iostream>
#include <algorithm>

typedef long long ll;
using namespace std;



ll cnt_temp2 = 0, cnt_temp5 = 0;

void cal(ll n) {

    cnt_temp2 = 0;
    cnt_temp5 = 0;

    while (n % 2 == 0 && n > 0) {

        n /= 2;
        cnt_temp2++;
        //cout << cnt_temp2 << endl;
    
    }

    while (n % 5 == 0 && n > 0) {

        n /= 5;
        cnt_temp5++;

    }

}

int main() {

    ll cnt2 = 0, cnt5 = 0;
    
    ll sum2 = 0, sum5 = 0;
    
    ll n;
    cin >> n;

    for (int i = 1; i <= n; i++) {

        cal(i);
        cnt2 += cnt_temp2;
        cnt5 += cnt_temp5;
        
        sum2 += cnt2;
        sum5 += cnt5;
        
        //cout << sum5 << endl;
    }

    cout << min(sum2, sum5) << endl;

    return 0;
}