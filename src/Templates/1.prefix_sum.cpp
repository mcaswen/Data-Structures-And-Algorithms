#include <iostream>
#include <vector>

using namespace std;

const int MAXSIZE = 10000;

vector <int> a(MAXSIZE, 0);
vector <int> sum(MAXSIZE, 0);


int main() {

    int n;
    cin >> n;

    sum[0] = 0;
    for (int i = 1; i <= n; i++) {

        a[i] = i;
        sum[i] += sum[i-1] + a[i];
    }

    int j,k;
    cin >> j >> k;

    cout << sum[k] - sum[j-1] << endl;

    return 0;
}