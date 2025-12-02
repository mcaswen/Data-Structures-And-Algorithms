#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


vector <int> pos(30, 0);

int n,r;

void printSubset(int cur) {

    if (cur == r) {

        for (int i = 0; i < cur; i++) {

            cout  << setw(3) << pos[i];

        }

        cout << endl;

    }

    int st = cur ? pos[cur-1] + 1 : 1;

    for (int i = st; i <= n; i++) {

        pos[cur] = i;
        printSubset(cur + 1);

    }

}

signed main() {

    cin >> n >> r;

    int cur = 0;
    printSubset(cur);

    return 0;
}

