#include <iostream>

using namespace std;

signed main() {

    int T;
    cin >> T;

    while (T--) {

        int num_of_1 = 0;
        int num_of_0 = 0;

        int n;
        cin >> n;

        string s;
        cin >> s;

        for (int i = 0; i < n; i++) {

            cout << s[i] << endl;

            if (s[i] == '1') {

                num_of_1++;

            } else if (s[i] == '0') num_of_0++;

        }

        if (num_of_0 > num_of_1) cout << "no" << endl;
        else cout << "yes" << endl;

    }

    return 0;
}