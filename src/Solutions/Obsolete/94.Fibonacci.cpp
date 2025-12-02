#include <iostream>
#include <vector>

using namespace std;

vector <int> arr(35, 0);

void cal(int n, int x, int y) {

    if (arr[n]) return;

    if (n >= 31) return;

    arr[n] = x + y;
    cal(n+1, arr[n], arr[n-1]);

}

signed main() {

    arr[1] = 1;
    arr[2] = 1;

    cal(3, arr[1], arr[2]);

    int T;
    cin >> T;

    while (T--) {

        int a;
        cin >> a;

        cout << arr[a] << endl;

    }

    return 0;
}