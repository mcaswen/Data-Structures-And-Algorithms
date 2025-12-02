#include <iostream>
typedef long long ll;
using namespace std;

int main() {

    ll num;
    cin >> num;

    for (ll i = 1; i <= num / 2;) {
        ll sum = i;
        ll j;
        
        for (j = i + 1; sum <= num; j++) {

            sum += j;
            //cout << sum << endl;
            if (sum == num) {

                cout << i << " " << j << endl;
                break;
            }

        }
        
        i++;

    }

    return 0;
}