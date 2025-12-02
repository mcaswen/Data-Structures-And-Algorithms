#include <iostream>

using namespace std;

int ka[10000];
int xa[10000];
int ya[10000];


int main() {

    int x, y, k;

    while (cin >> k) {

        int cnt = 0;

        for (y = k + 1; y <= 2 * k; y++) {
            if ((k * y) % (y - k) == 0) {
                
                xa[cnt] = (k * y) / (y - k);
                ya[cnt] = y;
                ka[cnt] = k;           
                
                cnt++;
 
            }

        }

        if ( cnt ) {
            cout << cnt << endl;

            for (int i = 0; i < cnt; i++) 
                cout << "1/" << ka[i] << " = 1/" << xa[i] << " + 1/" << ya[i] << endl;

        }
        else 
            cout << 0 << endl;


    }

    return 0;
}