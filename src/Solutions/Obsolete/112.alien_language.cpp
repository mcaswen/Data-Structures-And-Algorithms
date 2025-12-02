#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
vector <char> arr(20, 0);
vector <char> A(20, 0);

char list[] = {'a', 'e', 'i', 'o', 'u', };

bool check(int l) {

    //cout << "check" << endl;

    int num_of_yuan = 0;
    int num_of_fu = 0;
    bool ok = true;
    bool foundyuan = false;

    for (int i = 0; i < l; i++) {

        foundyuan = false;

        for (int j = 0; j < 5; j++) {
            
            if (A[i] == list[j]) {

                num_of_yuan++;
                foundyuan = true;

            }

        }

        if (!foundyuan){

            num_of_fu++;

        }

    }

    if (num_of_fu < 2 || num_of_yuan < 1) {

        ok = false;

    }

    return ok;

}

void permutation(int cur, int c, int l) {

    //cout << cur << endl;

    if (cur == l && check(l)) {

        for (int i = 0; i < l; i++) {

            cout << A[i];

        }
        
        cout << endl;

    } else for (int i = 1; i <= c && cur <= l; i++) {

        if (cur > 0 ) {

            if (A[cur-1] > arr[i])
                continue;

        }    

        bool Aflag = false;

        for (int j = 0; j < cur; j++) {
            if (arr[i] == A[j]) {
                
                Aflag = true;
                break;

            }
        }
        
        if (!Aflag) {
            
            A[cur] = arr[i];
            //cout << (char)arr[i] << endl;
            permutation(cur+1, c, l);
        
        }
    }

}

signed main() {

    int l, c;
    cin >> l >> c;
    cin.ignore();

    for (int i = 1; i <= c; i++) {

        cin >> arr[i];

        if (arr[i] == ' ') {

            i--;

        }

    }

    sort(&arr[1], &arr[c+1]);

    permutation(0, c, l);

    return 0;
}