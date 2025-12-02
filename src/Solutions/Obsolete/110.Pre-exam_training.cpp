#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 typedef struct {

    int v;
    int t;


 } QUES;

QUES ques[25];

bool fvalue(QUES a, QUES b) {

    return a.v > b.v;

}

bool ftime(QUES a, QUES b) {

    return a.t < b.t;

}

signed main() {

    int T;
    cin >> T;

    while (T--) {

        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {

            cin >> ques[i].t;

        }

        for (int i = 1; i <= n; i++) {

            cin >> ques[i].v;

        }

        sort(&ques[1], &ques[n+1], fvalue);

        int sum_v = 0;
        int time = m;

        for (int i = 1; i <= n; i++) {

            time -= ques[i].t;

            if (time < 0 ) break;

            sum_v += ques[i].v;

        }

        sort(&ques[1], &ques[n+1], ftime);

        int sum_t = 0;
        time = m;

        for (int i = 1; i <= n; i++) {

            time -= ques[i].t;

            if (time < 0 ) break;

            sum_t += ques[i].v;

        }

        if (sum_t > sum_v) cout << "A" << endl;
        else if (sum_t < sum_v) cout << "B" << endl;
        else cout << "SAME" << endl;

    }

    return 0;
}