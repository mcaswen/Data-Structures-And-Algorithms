#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector <int> a(200005, 0);
vector <int> b(200005, 0);
vector <ll> sum1(200005, 0);
vector <ll> sum2(200005, 0);

int main() {

    int n;int t;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = 1 - a[i];
    }
    ll sumle = 0; ll sumri = 0;
    for (int i = 1; i <= n; i++) {
        sum1[i] = sum1[i - 1] + a[i];

    }
    for (int j = n; j >= 1; j--) {
        sum2[j] = sum2[j + 1] + b[j];
    }
    
    for (int i = 1; i <= n; i++) {
        if (!a[i]) {
            sumle += sum1[i];

        }

    }

    for (int j = n; j >= 1; j--) {
        if (a[j]) {
            sumri += sum2[j];

        }

    }

    cout << min(sumri, sumle) << endl;


    return 0;
}