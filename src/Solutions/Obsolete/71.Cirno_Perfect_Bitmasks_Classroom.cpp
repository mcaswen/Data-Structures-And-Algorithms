    #include <iostream>
    #include <cmath>
    using namespace std;

    typedef long long ll;

    signed main() {

        int T;
        cin >> T;

        while (T--) {

            ll n;
            cin >> n;
            ll num = n;


            int cnt = 0;
            int idx = 0;

            for (int i = 1; i <= 31; i++) {
                
                if (cnt < 1)
                    idx++;
                
                if ((n & 1) == 1) {
                    
                    cnt++;

                }
            
                n = (n >> 1);

            }
            
            ll ans = 0;

            if (cnt > 1) {
                
                ans = pow(2, idx - 1);
                //cout << idx << endl;
            
            }
            
            else {
                
                ans = pow(2, idx - 1) + 1;
                //cout << idx << endl;
            
            }

            if (num == 1)
                ans = 3;
            
            cout << ans << endl;
        
        }

        return 0;
    }