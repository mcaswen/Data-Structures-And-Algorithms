#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int n = 0;
    cin >> n;

    for (int i = 0;i < n; i++) {

        int a,b;
        cin >> a >> b;

        int is0 = 0;

        if (b % 2 == 1) {
            if (a % 2 == 0 && a >= 2)
                is0 = 1;    

        }

        else {
            if (a % 2 == 0)
                is0 = 1;

        }
        
        
        if (is0) cout << "YES" << endl;
        else cout << "NO" << endl;
        
    }
    return 0;
}
