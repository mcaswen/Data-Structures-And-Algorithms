#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector <int> arr(1005, 0);
map <int, int> mp;

signed main() {

    int T;
    cin >> T;

    while (T--) {

        int n;
        cin >> n;

        mp.clear();

        for (int i = 1; i <= n; i++) {

            cin >> arr[i];
            mp[arr[i]]++;

        }

        int num_of_single = 0;
        int num_of_non_single = 0;
        int num = 0;
       

        for (const auto& p: mp) {

            if (p.second == 1) {

                num_of_single++;

            } else {
                
                num_of_non_single++;
            
            }
        
        }

        int sco = 0;

        //cout << num_of_non_single << " " << num_of_single;

        sco += num_of_non_single;

        sco +=  2 * ((num_of_single & 1) ? num_of_single / 2 + 1 : num_of_single / 2);

        cout << sco << endl;

    }

    return 0;
}