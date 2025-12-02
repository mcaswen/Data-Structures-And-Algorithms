#include <iostream>

using namespace std;

signed main() {

    int a, b;
    cin >> a >> b;

    int x = (a + b) / 2;
    int y = a - x;

    cout << x << " " << y;


    return 0;
}