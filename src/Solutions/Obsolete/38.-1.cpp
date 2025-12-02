#include <iostream>

using namespace std;

int main() {

    int t;
    cin >> t;

    for (; t; t--) {

        int a,b;
        cin >> a >>b;

        if ( a > b ) {
            int t = a;
            a = b;
            b = t;

        }

        cout << a << " " << b << endl;  

    }

    return 0;
}