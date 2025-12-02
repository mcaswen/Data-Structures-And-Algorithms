#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector <ll> a(500005, 0);
vector <ll> b(500005, 0);
ll sum = 0;


void inverse_pair(int le, int ri) {
    
    if (le >= ri) return;

    int m = (le + ri) / 2;

    inverse_pair(le, m);
    inverse_pair(m + 1, ri);

    int i = le;
    int k = le;
    int j = m + 1;

    while (i <= m && j <= ri) {

        if (a[j] >= a[i]) {
            b[k] = a[i];
            k++;
            i++;


        }
        else {

            b[k] = a[j];
            k++;
            j++;
            sum += m - i + 1;

        }
    }
        while (i <= m) {
            
            b[k] = a[i];
            k++;
            i++;
        }

        while (j <= ri) {

            b[k] = a[j];
            k++;
            j++;
        }

        for (int i = le; i <= ri; i++) {

            a[i] = b[i];

        }

}

int main() {

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];

    }

    inverse_pair(1, n);

    cout << sum << endl;

    return 0;
}