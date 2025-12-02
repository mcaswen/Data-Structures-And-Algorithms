#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
vector <int> arr(2e5+5, 0);
#define wa ac

signed main() {

    int n; cin >> n;
    bool zheng = false;

    for (int i = 1; i <= n; i++) {

        cin >> arr[i];

        if (arr[i] >= 0) zheng = true;

    }   

    ll sum = 0;
    ll ans = -0x3f3f3f3f;
    
    if (zheng) {
        for (int i = 1; i <= n; i++) {

            if (sum < 0) sum = arr[i];

            else sum += arr[i];

            ans = max(sum, ans);
        
        }

    } else {

        for (int i = 1; i <= n; i++) {

            ans = max((int)ans, arr[i]);
        
        }   

    }

    cout << ans << endl;

    return 0;
}