#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector <int> arr(100005, 0);
stack <int> sta;
vector <int> ans(100005, 0);

signed main() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {

        cin >> arr[i];

    }

    for (int i = n; i >= 1; i--) {

        while (sta.size() && arr[i] >= arr[sta.top()]) {

            sta.pop();

        }

        if (sta.size()) {

            ans[i] = sta.top();

        }

        sta.push(i);

    }

    for (int i = 1; i <= n; i++) {

        cout << ans[i] << endl;

    }

}