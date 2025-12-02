#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

map <int , ll> item[100005];

signed main() {

    int N, Q;
    cin >> N >> Q;

    while (Q--) {

        int type;
        cin >> type;

        if (type == 1) {

            int i, j;
            ll k;
            cin >> i >> j >> k;

            item[i][j] = k;

        } else {

            int i, j;
            cin >> i >> j;

            cout << item[i][j] << endl;

        }

    }

    return 0;
}