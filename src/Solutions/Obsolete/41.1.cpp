#include <iostream>
#include <vector>

using namespace std;

int main() {

    int t;
    cin >> t;

    for (; t; t--) {

        int n;
        cin >> n;

        vector < vector <char> > arr(n, vector <char> (n, '0'));
        int istr = 0;
        
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < n ; j++)
                cin >> arr[i][j];
        }
        
        for (int i = 0; i < n ; i++) {
            
            for (int j = 0; j < n ; j++) {

                if (j > 0 && j+1 < n) {                   
                    if (arr[i][j] == '1' && arr[i][j-1] == '0' && arr[i][j+1] == '0') {
                        istr = 1;    
                        break;
                    }
                }
            }        
            if (istr) break;
              
        }
        
        if (istr == 1) cout << "TRIANGLE" << endl;    
        else cout << "SQUARE" << endl;

        
    }
    return 0;
}            