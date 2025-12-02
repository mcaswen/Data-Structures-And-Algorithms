#include <iostream>
#include <vector>

using namespace std;

 vector < int > a(200005 ,0);

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        long long k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++) {

            cin >> a[i];

        }
        
        int cntm = 0;
        
        int o = 1;    
        int j = n;
        long long ka = (k + 1) / 2;
        long long kb = k - ka;

            for (; o <= n; o++) {
                
                if (a[o] != 0) {
                
                    if (a[o] <= ka ) {
                        ka -= a[o];
                        a[o] = 0;
                        cntm++;
                    } 
                    
                    else {
                        
                        a[o] -= ka;
                        ka = 0;                   
                        break;          
                    }
                }
            
            }

            for (; j >= 1; j--) {
                
                if (a[j] != 0) {
                
                    if (a[j] <= kb) {
                        kb -= a[j];
                        a[j] = 0;
                        cntm++;
                    } 
                    else {

                        a[j] -= kb;
                        kb = 0;
                        break;
                    }
                }        
        
        }


        cout << cntm << endl;


    }

    return 0;
}