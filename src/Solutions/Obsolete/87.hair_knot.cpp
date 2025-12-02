#include <iostream>
#include <vector>
#include <stack>

using namespace std;
typedef long long ll;


vector <ll> arr(8e4 + 5, 0);
vector <ll> ans(8e4 + 5, 0);

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {

        cin >> arr[i];

    }

    stack <ll> s;

    for (int i = N; i >= 1; i--) {

        while (s.size() && arr[i] > arr[s.top()]) {
            
            ans[i] += ans[s.top()] + 1;
            s.pop();

        }   

        s.push(i);

    }

    ll a = 0;
    for (int i = 1; i <= N; i++) {

        a += ans[i];

    }

    cout << a << endl;

    return 0;

}
