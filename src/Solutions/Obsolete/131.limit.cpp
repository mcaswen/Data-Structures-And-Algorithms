#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> arr(1e5+5, 0);
deque <int> maxdq;
deque <int> mindq;

bool check(int lim, int num) {

    if (!maxdq.size()) return true;

    return max(arr[maxdq.front()], num) - min(arr[mindq.front()], num) <= lim;

}

void push(int i) {

    while (maxdq.size() && arr[i] >= arr[maxdq.back()])
        maxdq.pop_back();

    while (mindq.size() && arr[i] <= arr[mindq.back()])
        mindq.pop_back();

    maxdq.push_back(i);
    mindq.push_back(i);

}

void pop(int le) {

    if (maxdq.front() == le) maxdq.pop_front();
    if (mindq.front() == le) mindq.pop_front();

}

int solve(int lim) { 

    int ans = 0;
    int ri = 0;
    int n = arr.size();

    for (int le = 0; le < n; le++) {

        while (ri < n && check(lim, arr[ri])) {

            push(ri++);

        }

        ans = max(ans, (int)maxdq.size());

        pop(le);

    }

    return ans;

} 