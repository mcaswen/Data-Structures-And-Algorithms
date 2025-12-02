#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
ll a[100005];

int main() {

    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];

    }

    sort(a + 1, a + n + 1);

    ll min1 = 100000000;
    ll max5 = 0;
    
    if (n != 1 && n != 0) {
        for (int i = 1; a[i] + n - 1 <= a[n]; i++) {
            int cnt = i + 1;
            int sum = 0;
            
            while (cnt <= n && a[i] + n - 1 >= a[cnt] ) {
                    sum += a[cnt] - a[cnt - 1] - 1;
                    cnt++;
            }      
            
            sum += a[i] + n - 1 - a[cnt - 1];        

            if (sum < min1)
                min1 = sum;

        }
        
        int ispe = 1;
        for (int i = 1; i <= n - 2; i++) {
            if (a[i+1] - a[i] > 1) {
                ispe = 0;
                break;
            }
        }

        if (ispe && a[n] - a[n-1] > 2)
            min1 = 2;
        
        int ispe2 = 1;
        for (int i = 2; i <= n-1; i++) {
            if (a[i+1] - a[i] > 1) {
                ispe2 = 0;
                break;
            }
        }

        if (ispe2 && a[2] - a[1] > 2)
            min1 = 2;
    }
    else    
        min1 = 0;


    int max3 = 0;
    int max4 = 0;

    for (int i = 2; i <= n - 1; i++) {
        max3 += a[i+1] - a[i] - 1;

    }

    for (int i = 1; i <= n - 2; i++) {
        max4 += a[i+1] - a[i] - 1;

    }

    int max2 = max(max3, max4);

    cout << min1 << endl << max2;    
    
    return 0;
}