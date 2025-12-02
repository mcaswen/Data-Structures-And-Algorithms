#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;
ll a[100005];

int main() {

    int time;
    cin >> time;

    for (; time; time--) {

        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        sort(a + 1, a + n + 1);

        int isc = 0;
        if ((a[1] % a[2]) == 0) {
            for (int j = 3; j <= n; j++) {
                if ((a[j] % a[1]) != 0) {                       
                    a[0] = a[j];
                    for (int k = j; k < n; k++) {
                        a[k] = a[k+1];

                    }                         
                isc = 1;
                break;
                }
            }
        }
        

        bool ans = true;
        int cnt = 1;
        int nn = n;
        
        if (isc) {
            cnt = 0;
            nn = n - 1;
        }
        
        //for (; cnt <= nn; cnt++) 
            //cout << a[cnt] << " ";

            //cout << endl;

        //cout << isc << endl;
        
        for (; cnt < nn; cnt++) {
            //cout << a[cnt+1] << " " << a[cnt] << endl;
            a[cnt+1] = a[cnt] % a[cnt+1];

            if (a[cnt+1] == 0) {
                ans = false; 
                break;            
            }
        
        }

        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }

    return 0;
}