        #include <iostream>

        using namespace std;

        int main() {

            int t;
            cin >> t;

            for (; t; t--) {

                int n,k;
                cin >> n >> k;
                
                int cnt = 0;
                int mon = 0;
                
                for (; n; n--) {

                    int ai;
                    cin >> ai;

                    if (ai >= k) mon = mon + ai;

                    if (mon > 0 && ai == 0) {
                    
                        mon--;
                        cnt++;

                    }

                }   

                cout << cnt << endl;

            }

            return 0;
        }