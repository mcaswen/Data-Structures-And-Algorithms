#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;
vector <ll> arr(100005, 0);

int main() {

    int n, t;
    cin >> n;

    ll mini = 1;
    
    for (int i = 1; i <= n; i++) {

        cin >> arr[i];
        if (i == 1)
            mini = arr[i];

       mini = min(mini, arr[i]);

    }

    ll sum = 1;

    for (int i = 1; i<= n; i++) {

        sum *= arr[i] / mini;
        sum %= mod;
    
    }

    cout << mini << " " << sum % mod << endl;

    return 0;
}