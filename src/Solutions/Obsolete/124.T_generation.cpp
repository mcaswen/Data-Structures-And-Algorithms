#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

map <ll, int> mp;

bool mmax(map <ll, int> &mp, ll a, ll b) {

    return mp[a] > mp[b];

}

vector <ll> keys;

signed main() {

    int T;
    cin >> T;

    while (T--) {

        int n, k;
        cin >> n >> k;

        mp.clear();
        keys.clear();
        
        for (int i = 1; i <= n; i++) {

            ll num;
            cin >> num;

            mp[num]++;

        }

        //cout << mp.size() << endl;

        for (auto p: mp) {

            keys.push_back(p.first);
            //cout << p.first << endl;

        }

        sort(keys.begin(), keys.end(), [](ll a, ll b) {

            return mmax(mp, a, b);

        });


            int k_size = keys.size();

            for (int i = keys.size() - 1; i >= 1 && k > 0; i--) {

                if (k >= mp[keys[i]]) {
                    
                    //cout << "shan" << endl;

                    mp[keys[0]] += mp[keys[i]];
                    keys.pop_back();
                    k -= mp[keys[i]];
                    mp.erase(keys[i]);

                } else {
                   
                    mp[keys[i]] -= k;
                    mp[keys[0]] += k;
                    k = 0;
                
                }
            }

        cout << mp.size() << endl;

    }

    return 0;
}