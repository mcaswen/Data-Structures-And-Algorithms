#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector <long long> arr(100, 0);
int main() {

    int n;
    cin >> n;

    arr[1] = arr[2] = 1;
    int i = 0;

    for (i = 3; i <= n; i++) {

        arr[i] = arr[i-1] + arr[i-2];

    }



    cout << fixed << setprecision(2) << (double)arr[n] << endl;

    return 0;
}