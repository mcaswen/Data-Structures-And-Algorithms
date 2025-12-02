#include <iostream>
#include <deque>
#include <vector>

using namespace std;
vector <vector <int> > arr(1e5+5, vector <int>(1e5+5, 0));
deque <int> dq;

int seek(int k) {

    int ans = -0x3f3f3f3f;
    int n = arr.size();

    for (int i = 0; i < n; i++) {

        int x = arr[i][0];
        int y = arr[i][1];

        while (dq.size() && arr[dq.front()][0] + k < x) {

            dq.pop_front();

        }

        if (dq.size())
            ans = max(ans, x + y + arr[dq.front()][1] - arr[dq.front()][0]);

        while (dq.size() && y - x >= arr[dq.back()][1] - arr[dq.back()][0]) {

            dq.pop_back();

        }

        dq.push_back(i);

    }

    return ans;

}