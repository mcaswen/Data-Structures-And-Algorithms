#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> arr(15, 0);
vector <int> pos(15, 0);

int n, s, ans;

void findSubset(int cur) {

    if (cur > ans) {

        int sum = 0;
        int mini = arr[pos[0]];

        for (int i = 0; i < cur; i++) {

            sum += arr[pos[i]];
            mini = min(arr[pos[i]], mini);
            
        }

        //cout << sum << " " << (mini) << endl;

        if (sum >= s && mini > sum - s) 
            ans = cur;

    }

    int st = cur ? pos[cur-1] + 1 : 0;

    for (int i = st; i < n; i++) {

        pos[cur] = i;
        findSubset(cur + 1);

    }

}
signed main() {

    int TIM;
    cin >> TIM;

    while (TIM--) {

        cin >> n >> s;

        int cur = 0;
        ans = 0;

        for (int i = 0; i < n; i++) {

            cin >> arr[i];

        }

        findSubset(cur);

        cout << ans << endl;


    }

    return 0;
}