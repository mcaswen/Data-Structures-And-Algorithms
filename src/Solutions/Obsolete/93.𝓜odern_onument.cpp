#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

vector <ll> arr(55, 0);
map <ll, int> mp;

signed main() {

    int T;
    cin >> T;

    while (T--) {
        
        mp.clear();

        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {

            cin >> arr[i];
            mp[arr[i]]++;

        }

        auto max_value = *max_element(mp.begin(), mp.end(), 
                        [](const pair <ll, int> &a, const pair <ll, int> &b) {

                            return a.second < b.second;

                        });

        if (mp.size() > 1) {

            cout << n - max_value.second << endl;
 
        } else {

            cout << 0 << endl;

        }

    }

    return 0;
}