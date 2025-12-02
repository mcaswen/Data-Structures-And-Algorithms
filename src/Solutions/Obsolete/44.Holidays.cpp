#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    int m;
    cin >> n >> m;

    vector <int> arr(n+100, 0);
    vector <int> brr(n+100, 0);
    int isok = 1;

    for (; m ; m--) {

        int a,b;

        cin >> a >> b;
        
        
        brr[a] += 1;
        
        if (b+1 <= n)
            brr[b+1] -= 1;

        
    }

    for (int i = 1; i <= n ; i++) {

            arr[i] += arr[i-1] + brr[i];      
        
        }
        
    for (int i = 1; i <= n ; i++) {

        if (arr[i] > 1 || arr[i] == 0) {

            cout << i << " " << arr[i] << endl;
            isok = 0;
            break;
        
        }    
        
    }

    if (isok) 
            cout << "OK" << endl;

    return 0;
}