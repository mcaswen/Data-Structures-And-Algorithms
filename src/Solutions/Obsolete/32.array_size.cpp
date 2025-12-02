#include <iostream>
#include <vector>

using namespace std;

vector <long long> arr(10000000, 0);

int main() {

    int time;   
    cin >> time;

    for (; time > 0; time--) {

        int k = 0;
        int n = 0;
        cin >> n >> k;

        int size = k;
        k--;
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];

        }
        
        if (size > n) 
            cout << -1 << endl;              
        else 
            cout << arr[k] << endl;

    }

    return 0;
}

