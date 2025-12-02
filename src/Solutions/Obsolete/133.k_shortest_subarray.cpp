#include <iostream>
#include <deque>
#include <vector>

using namespace std;

deque <int> dq;
vector <int> sum(1e5+5, 0);

int find(vector <int>& arr, int k) {

    int n = arr.size();

    for (int i = 0; i < n; i++) {

        sum[i+1] += sum[i] + arr[i];

    }

    int ans = 0x3f3f3f3f;

    for (int i = 0; i <= n; i++) {

        while (dq.size() && sum[i] - sum[dq.front()] >= k) {

            ans = min(ans, i - dq.front());
            dq.pop_front();

        }

        while (dq.size() && sum[i] <= sum[dq.back()]) {

            dq.pop_back();

        }

        dq.push_back(i);

    }

    return (ans == 0x3f3f3f3f ? -1 : ans);

}