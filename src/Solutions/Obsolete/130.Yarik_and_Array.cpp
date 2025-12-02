#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> arr(2e5 + 5, 0);

signed main() {

    int t; cin >> t;
    
    while (t--) {

        arr.clear();

        int n;
        cin >> n;

        bool positive = false;

        for (int i = 1; i <= n; i++) {

            cin >> arr[i];

            if (arr[i] >= 0) positive = true;

        }
        
        long long ans = -0x3f3f3f3f;

        if (positive) {
            
            int pre = -1;
            int cur = 0;
            long long sum = 0;

            for (int i = 1; i <= n; i++) {

                cur = arr[i] & 1;
                if (i > 1) pre = arr[i-1] & 1;
                
                if (cur == pre || sum < 0) sum = arr[i];
                else sum += arr[i];

                ans = max(sum, ans);
                
            }
        
        } else {

            for (int i = 1; i <= n; i++) {

                ans = max((int)ans, arr[i]);

            }

        }

        cout << ans << endl;

    }

    return 0;
}