#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> arr(20, 0);
vector <int> pos(20, 0);

long long mini, maxx, ans, n, sub;

void findSubset(int cur) {

    if (cur >= 2) {

        int sum = 0;
        int mi = arr[pos[0]];
        int ma = arr[pos[0]];
        
        for (int i = 0; i < cur; i++) {

            sum += arr[pos[i]];
            mi = min(arr[pos[i]], mi);
            ma = max(arr[pos[i]], ma);
        
        }

        //cout << sum << " " << (mini) << endl;

        if (sum >= mini && sum <= maxx && (ma - mi) >= sub) 
            ans++;

    }

    int st = cur ? pos[cur-1] + 1 : 0;

    for (int i = st; i < n; i++) {

        pos[cur] = i;
        findSubset(cur + 1);

    }

}
signed main() {
   

        cin >> n >> mini >> maxx >> sub;

        int cur = 0;
        ans = 0;

        for (int i = 0; i < n; i++) {

            cin >> arr[i];

        }

        findSubset(cur);

        cout << ans << endl;


    return 0;
}