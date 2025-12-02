    #include <iostream>

    using namespace std;

    int main() {

        int t;
        cin >> t;

        for (; t; t--) {

            string a, b;

            cin >> a >> b;

            char c = a[0];
            a[0] = b[0];
            b[0] = c;
            
            cout << a << " " << b << endl;

        }

        return 0;
    }