#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long> a(100005, 0);
vector <long long> b(100005, 0);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (; t; t--) {

        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            
            cin >> a[i];
            b[i] = a[i];
        
        }

        sort(a.begin() + 1, a.begin() + n + 1);

        if (n != 2) {

            if (a[n] == a[n-1] && a[n-1] == a[n-2])
                cout << a[n] << endl;
            
            else if (a[n] == a[n-1]) {
                if (b[1] == a[n] && b[n] == a[n])
                    cout << a[n-1] << endl;
                
                else 
                    cout << a[n] << endl;

            }

            else {
                if (b[1] == a[n] && b[n] == a[n-1] || b[1] == a[n-1] && b[n] == a[n])
                    cout << a[n-2] << endl;
                
                else if (b[1] == a[n] || b[n] == a[n])
                    cout << a[n-1] << endl;
                
                else 
                    cout << a[n] << endl;

            } 
        }

        else
            cout << a[1] << endl;

    }
    
    return 0;
}