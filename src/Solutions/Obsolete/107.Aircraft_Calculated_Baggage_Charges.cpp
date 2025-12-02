#include <iostream>
#include <iomanip>

using namespace std;

signed main() {

    double s;
    cin >> s;

    if (s <= 20) {

        cout << fixed << setprecision(2) << s * 1.68 << endl;

    } else {

        cout << fixed << setprecision(2) << s * 1.98 << endl;

    }

    return 0;
}