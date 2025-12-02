#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

#define MAX 0x3f3f3f3f
typedef long long ll;
#define wa ac

vector <ll> arr(1e6+5, 0);

//一个数组中都是正数，输入一个n,求和至少为n的最小子数组
int seek(int n, int size) {

    int le = 1;
    int ri = 1;
    int ans = MAX;
    int sum = 0;

    int len = 1;

    while (ri < size) {

        ri++;
        sum += arr[ri];
        len++;

        while (1) {

            if (sum - arr[le] >= n) {

                sum -= arr[le];
                le++;
                len--;
                ans = min(len, ans);

            } else break;

        }

    }

    return ans;

}

//单调队列，数组中可以有负数

deque <ll> dq_max;
deque <ll> dq_min;
vector <ll> mini;
vector <ll> maxi;

void sliding_max(int n, int k) {

    for (int i = 1; i < k; i++) {

        while (dq_max.size() && arr[i] >= arr[dq_max.back()]) {

            dq_max.pop_back();

        }

        dq_max.push_back(i);

    }

    for (int le = 1, ri = k ;ri <= n; le++, ri++) {

        while (dq_max.size() && arr[dq_max.back()] <= arr[ri]) {

            dq_max.pop_back();

        } 

        dq_max.push_back(ri);

        maxi.push_back(arr[dq_max.front()]);

        if (dq_max.front() == le) {

            dq_max.pop_front();

        }

    }

}

void sliding_mini(int n, int k) {

    for (int i = 1; i < k; i++) {

        while (dq_min.size() && arr[i] <= arr[dq_min.back()]) {

            dq_min.pop_back();

        }

        dq_min.push_back(i);

    }

    for (int le = 1, ri = k; ri <= n; le++, ri++) {

        while (dq_min.size() && arr[ri] <= arr[dq_min.back()]) {

            dq_min.pop_back();

        }

        dq_min.push_back(ri);

        mini.push_back(arr[dq_min.front()]);

        if (dq_min.front() == le) {

            dq_min.pop_front();

        }

    }

}

signed main() {

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {

        cin >> arr[i];

    }

    sliding_mini(n, k);

    for (auto p: mini) {

        cout << p << " ";

    }

    cout << endl;

    sliding_max(n, k);

    for (auto p: maxi) {

        cout << p << " ";

    }

}