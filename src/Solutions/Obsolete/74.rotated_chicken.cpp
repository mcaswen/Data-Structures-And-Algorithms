#include <iostream>
#include <vector>
using namespace std;

vector <int> arr(11, 1);
vector <int> arr2(11, 1);

int ans;

void permutation1(int n, int cur) {

    if (cur > 10) {

        int sum = 0;

        for (int i = 1; i <= 10; i++) {

            sum += arr[i];

        }

        if (sum == n)
            ans++;

        return;
    
    }

    else {

        for (int i = 1; i <= 3; i++) {
            
            arr[cur] = i;
            
            permutation1(n, cur+1);

        }

    }

}

void permutation2(int n, int cur) {

    if (cur > 10) {

        int sum = 0;

        for (int i = 1; i <= 10; i++) {

            sum += arr2[i];

        }

        if (sum == n) {

            for (int i = 1; i <= 10; i++) {

                cout << arr2[i] << " ";

            }
        
            cout << endl;
        
        }
        
        return;
    
    }
    else {

        for (int i = 1; i <= 3; i++) {
            
            arr2[cur] = i;
            
            permutation2(n, cur+1);

        }

    }

}


int main() {

    int n; int ac;
    cin >> n;


    int cur = 1;

    ans = 0;

    permutation1(n, cur);



    if (n < 10 || n > 30)
        
        cout << 0 << endl;
    
    
    else {
        
        cout << ans << endl;

        cur = 1;

        permutation2(n, cur);
        //cout << 1;
    }

    return 0;
}