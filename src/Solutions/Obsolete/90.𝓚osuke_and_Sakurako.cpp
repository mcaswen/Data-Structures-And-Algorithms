#include <iostream>

using namespace std;

signed main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;   

        int pos = 0;
        int i = 1;
        int temp = 1;

        while (true) {

            temp *= -1;

            pos += (i * 2 - 1) * temp;

            if (pos > n || pos < -1 * n) {

                break;

            }

            i++;

        }

        cout << ((i & 1) ? "Sakurako" : "Kosuke") << endl;

    }


}