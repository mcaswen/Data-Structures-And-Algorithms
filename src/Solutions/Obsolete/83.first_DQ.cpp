#include <iostream>
#include <deque>
#include <vector>

using namespace std;

typedef long long ll;

vector <ll> arr(1000005, 0);
vector <ll> ans(1000005, 0);

signed main() {

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {

        cin >> arr[i];

    }

    deque <ll> window;

    //min

    for (int i = 1; i <= N; i++) {

        while (window.size() && window.front() < i - M + 1) {

            window.pop_front();

        }

        while (window.size() && arr[i] < arr[window.back()]) {

            window.pop_back();

        }

        window.push_back(i);

        if (i >= M) {
            
            ans[i - M + 1] = arr[window.front()];

        }
    
    }

    for (int i = 1; i <= N - M + 1; i++) {

        cout << ans[i] << " ";

    }

    cout << endl;

    //max

    window.clear();

    for (int i = 1; i <= N; i++) {

        while (window.size() && window.front() < i - M + 1) {

            window.pop_front();

        }

        while (window.size() && arr[i] > arr[window.back()]) {

            window.pop_back();

        }

        window.push_back(i);

        if (i >= M) {
            
            ans[i - M + 1] = arr[window.front()];

        }
    
    }

    for (int i = 1; i <= N - M + 1; i++) {

        cout << ans[i] << " ";

    }

    return 0;
}