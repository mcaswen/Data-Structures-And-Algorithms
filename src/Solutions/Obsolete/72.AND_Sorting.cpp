#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> arr(2 * 10e5 + 7, 0);
vector <int> ans(2 * 10e5 + 7, 0);

signed main() {

    int T;
    cin >> T;

    while (T--) {

        int n;
        cin >> n;

        int cnt = 0;

        for (int i = 0; i <= n-1; i++) {
            
            cin >> arr[i];
            if (arr[i] != i) {
                cnt++;
                //cout << arr[i] << endl;
                
                if (cnt == 1)
                    ans[cnt] = arr[i];

                else 
                    ans[cnt] = arr[i] & ans[cnt-1];

            }

        }

        cout << ans[cnt] << endl;

    }

    return 0;

}