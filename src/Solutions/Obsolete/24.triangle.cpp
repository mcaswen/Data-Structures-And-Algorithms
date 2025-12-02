#include <iostream>

using namespace std;

int main() {

    int n = 0;
    cin >> n;
    int j = 1;

    for (; n > 0; n--) {
        
        for (int i = 1; i <= n; i++) {
            
            if (j < 10) cout << 0 << j;
            else cout << j;
            j++;
        }

        cout << endl;

    }

    return 0;
}
