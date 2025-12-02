#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef long long ll;
 
vector <int> zero(4005, 0);
ll mod = 1e9 + 7;

int T;

int findT (int k) {

    T = 0; int cnt = 0; 

    pair <ll, ll> now(1, 1), pos(1, 2);

    do {

        T++;

        now = pair <ll , ll> (now.second % k, (now.first + now.second) % k);

        pos.first++; pos.second++;

        if (now.first == 0) {
            zero[++cnt] = pos.first;
        }

    } while (now != pair <ll, ll> (1, 1));

    return cnt;

}


int main() {

    
    int t;
    cin >> t;

    for (; t ; t--) {
        ll n;
        int k;

        cin >> n >> k;

        if (k == 1) {

            cout << n % mod << endl;
            continue;

        }


        int cnt = findT(k);
        //cout << T << endl;

        ll numof0 = cnt;
        ll numofT = n / numof0;
        //cout << numofT << endl;
        ll locofT = n % numof0;

        ll ans = ((numofT % mod) * T % mod + zero[locofT]) % mod;

        cout << ans << endl;

    }

    return 0;
}