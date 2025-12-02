#include <iostream>
#include <vector>

using namespace std;

vector <int> A(100, 0);

void permutation(vector <int> &A, int n, int cur) {

    if (cur == n) {
        for (int i = 0; i < n; i++) {

            cout << A[i] << " ";

        }

        cout << endl;
        
        return;
    
    }

    else for (int i = 1; i <= n; i++) {

        int Aflag = 0;

        for (int j = 0; j < cur; j++) {
            if (i == A[j]) {
                
                Aflag = 1;
                break;

            }
        }

        if (!Aflag) {

            A[cur] = i;

            permutation(A, n, cur+1);

        }
    }

}

signed main() {

    int n;
    cin >> n;

    int cur = 0;

    permutation(A, n, cur);

    do {

        for (auto p: A) cout << p << " ";
        cout << endl;

    } while (next_permutation(A.begin(), A.end()));

    return 0;
}