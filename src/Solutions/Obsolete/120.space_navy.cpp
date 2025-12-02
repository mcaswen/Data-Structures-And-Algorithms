#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int bucket[105];

signed main() {

    int T;
    cin >> T;

    while (T--) {

        memset(bucket, 0, sizeof(bucket));

        int n;
        cin >> n;

        int max_num = 0;

        for (int i = 1; i <= n; i++) {

            int num;
            cin >> num;

            bucket[num]++;
            max_num = max(max_num, num);

        }

        bool ok = true;

        for (int i = 0; i < max_num; i++) {

            if (bucket[i+1] > bucket[i]) {

                ok = false;
                cout << "no" << endl;
                break;

            }

        }

        if (ok) cout << "yes" << endl;

    }


    return 0;
}