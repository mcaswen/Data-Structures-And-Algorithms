#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector <ll> pri(100005);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        
        cin >> pri[i];

    }

    sort(pri.begin() + 1, pri.begin() + n + 1);

    int day;
    cin >> day;
    for (int i = 1; i <= day; i++) {

        ll co;
        cin >> co;

        int p = upper_bound(pri.begin() + 1, pri.begin() + n + 1, co) - pri.begin() - 1;

        //if (pri[1] > co)
            //p = 0;


        cout << p << endl;
       
    }

    return 0;
}