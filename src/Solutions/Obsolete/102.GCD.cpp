#include <iostream>
#include <deque>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

map <ll, ll> mp[5005], visited[5005];
deque < pair<ll, ll> > dq;

vector < ll > ans;

ll gcd(ll a, ll b) {

    return b ? gcd(b, a % b) : a;

}

ll min(ll a, ll b) {

    return a < b ? a : b;

}


signed main() {

    int T, ac;
    cin >> T;

    while (T--) {
        
        for(int i = 0; i < 5005; i++) {
            
            mp[i].clear();
            visited[i].clear();
        
        }
        
        dq.clear();
        ans.clear();

        ll a, b;
        cin >> a >> b;

        dq.push_back(make_pair(a, b));
        mp[a][b] = 0;
        visited[a][b] = 1;

        while (dq.size()) {

            ll ma = dq.front().first;
            ll mb = dq.front().second;
            dq.pop_front();

            if (ma > 0) {

                ll na = ma - gcd(ma, mb);
                ll nb = mb;

                if (na == 0 && nb == 0) {

                    ans.push_back(mp[ma][mb] + 1);
                    break;

                }

                if (visited[na][nb] != 1) {

                    mp[na][nb] = mp[ma][mb] + 1;
                    visited[na][nb] = 1;
                    dq.push_back(make_pair(na, nb));

                }

            }

            if (mb > 0) {

                ll nb = mb - gcd(ma, mb);
                ll na = ma;

                if (na == 0 && nb == 0) {

                    ans.push_back(mp[ma][mb] + 1);
                    break;

                }

                if (visited[na][nb] != 1) {

                    mp[na][nb] = mp[ma][mb] + 1;
                    visited[na][nb] = 1;
                    dq.push_back(make_pair(na, nb));

                }

            }

        }

        ll num = 1e9 + 5;

        for (auto p: ans) {

            num = min(num, p);

        }

        cout << num << endl;
    
    }

    return 0;

}