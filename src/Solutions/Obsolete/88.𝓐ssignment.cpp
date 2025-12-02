#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector <int> arr(1e5+5, 0);
vector <long long> sum(1e5+5, 0);

typedef struct 
{
    int st;
    int en;

} SEQ;

SEQ seq[100005];

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int Time;
    cin >> Time;

    while (Time--) {

        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {

            cin >> arr[i];
            sum[i] = arr[i] + sum[i-1];

        }

        int ans = 0;

        for (int k = 1; k <= n; k++) {

            for (int i = 0; i + k <= n; i++) {

                bool isans = false;

                if (sum[i + k] - sum[i] == 0) {

                    isans = true;

                    if (ans > 0) {

                        for (int j = 1; j <= ans; j++) {

                            if (!((i + k < seq[j].st) || (i + 1 > seq[j].en))) {
                                
                                isans = false;
                                break;

                            }

                        }

                    }

                    if (isans) {

                        ans++;
                        seq[ans].st = i + 1;
                        seq[ans].en = i + k;

                        //cout << i << " " << i + k << endl;

                    }

                }

            }
        
        }

        cout << ans << endl;

    }
    
    return 0;

}