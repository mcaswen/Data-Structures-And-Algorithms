#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned int us;

vector <us> arr(1e5 + 7, 0);
vector <us> sum(1e5 + 7, 0);

int main() {

    int T;
    cin >> T;

    for (; T; T--) {
        ll k;
        int n;

        cin >> n >> k;

        for (int i = 1; i <= n; i++) {
            
            cin >> arr[i];
            if (i == 1)
                sum[i] = arr[i];
            
            else 
                sum[i] = arr[i] ^ sum[i-1];

        }
    
        if ((n & 1) == 1) {
            for (int j = 1; j <= n; j++)
                cout << (arr[j] ^ sum[n]) << ' ';

        }
        else {
            if ((k & 1) == 1)
                for (int j = 1; j <= n; j++)
                    cout << (arr[j] ^ sum[n]) << ' ';

            else 
                for (int j = 1; j <= n; j++)
                    cout << (arr[j]) << ' ';

        }
    
        cout << endl;

    }

    return 0;
}
