#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

vector <int> arr(1001, 0);
vector < vector <ll> > c(1005, vector <ll>(1005, 0));
int n, m;
const int mod = 1000000007;

void getc() {

    for (int i = 0; i <= 1001; i++) {
        c[i][0] = 1;
        c[i][i] = 1;

    }

    for (int i = 1; i <= 1001; i++) {
        for (int j = 1; j <= i; j++) {

            c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;

        }
    }
}


int main() {

    int time;
    cin >> time;

    getc();
    
    for (; time; time--) {
        cin >> n >> m;

        int total = 0;
        for (int i = 1; i <= m; i++) {

            cin >> arr[i];
            total += arr[i];
        }

        int num = n;
        ll ans = 1;
        
        if (total == n) {
        for (int i = 1; i <= m && num > 0; i++) {
            
            //cout << num << " " << arr[i] << " " << c[num][arr[i]] << endl;         
            
            ans = (ans * c[num][arr[i]]) % mod;
            num -= arr[i];
        
        }

        cout << ans % mod << endl;
        }
    
        else {
            //cout << "not" << endl;
            
            ans = 0;
            
            for (int j = 1; j <= m; j++) {
                
                ll ans_temp = 1;
                arr[j]--;
                num = n;
                
                for (int i = 1; i <= m && num > 0; i++) {   
                    
                    if (arr[i] == 0)
                        continue;

                    //cout << num << " " << arr[i] << " " << c[num][arr[i]] << endl;    

                    ans_temp = (ans_temp * c[num][arr[i]]) % mod;
                    num -= arr[i];
                
                }
                ans += ans_temp;                  
                arr[j]++;
            
            }

            cout << ans % mod << endl;
        
        }
    
    }

    return 0;

}

