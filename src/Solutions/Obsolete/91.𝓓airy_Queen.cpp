#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;
vector <char> arr(4e5 + 5, 0);

signed main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        set <int> set_0;
        set <int> set_1;

        for (int i = 1; i <= n; i++) {

            cin >> arr[i];
            
            if (arr[i] == '1') {
                

                //cout << i << endl;
                set_1.insert(i);

            } else {

                set_0.insert(i);

            }

        }

        ll cost = 0;

        for (auto p = set_1.rbegin(); p != set_1.rend(); ) {

            auto lower = set_0.lower_bound(*p);
            
            //cout << *p << endl;
            
            if (lower == set_0.begin())
                break;
            
            lower--;
            
            if (*lower < *p) {

                cost += *lower;

                set_0.erase(*lower);
                set_1.erase(*p);

            } else break;
        
        }

        for (auto p = set_1.rbegin(); p != set_1.rend(); ) {

            if (set_1.size() > 1) {

                cost += *set_1.begin();
                set_1.erase(*set_1.begin());
                set_1.erase(*p);

            } else break;

        }

        for (auto p: set_0) {

            cost += p;

        }

        for (auto p: set_1) {

            cost += p;

        }

        cout << cost << endl;
    
    }


    return 0;

}

