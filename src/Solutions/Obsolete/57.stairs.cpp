#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

vector <ll> arr(100005, -1);
int k;


ll cal(ll n) {

    if (arr[n] != -1)
        return arr[n];

    if (n == 0 || n == 1) {
       
        //cout << arr[n] << endl;

        return arr[n] = 1;
    
    }
    
    else {
        
        ll sum = 0;
        for (int i = 1; i <= k && n - i >= 0; i++) {
            
            sum = (cal(n - i) + sum) % 100003;

        }

        arr[n] = sum;
        
        //cout << arr[n] << endl;

        return arr[n];

    }

}


int main() {

    int n;
    cin >> n >> k;

    ll ans = (cal(n) + 100003) % 100003;

    cout << ans << endl;

    return 0;
}