#include <iostream>
#include <deque>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
int N, D;

map <int, int> mp;
deque <int> maxdq;
deque <int> mindq;
struct ele {

    int x;
    int y;

};

vector <ele> arr;

bool check() {

    int maxi = maxdq.size() ? arr[maxdq.front()].y : 0;
    int mini = mindq.size() ? arr[mindq.front()].y : 100000;

    return maxi - mini >= D;

}

void push(int p) {

    while (maxdq.size() && arr[p].y >= arr[maxdq.back()].y) maxdq.pop_back();
    while (mindq.size() && arr[p].y <= arr[mindq.back()].y) mindq.pop_back();

    maxdq.push_back(p);
    mindq.push_back(p);

}

void pop(int le) {

    if (maxdq.size() && maxdq.front() == le) maxdq.pop_front();
    if (mindq.size() && mindq.front() == le) mindq.pop_front();

}

signed main() {

    cin >> N >> D;
    arr.resize(N);

    for (int i = 0; i < N; i++) {

        cin >> arr[i].x >> arr[i].y;

    }

    sort(arr.begin(), arr.end(), [](ele a, ele b) {

        return a.x < b.x;

    });

    int ans = 0x3f3f3f3f;

    for (int le = 0, ri = 0; le < N; le++) {

        while (ri < N && !check()) {
            
            push(ri++);
            
        }
 
        if (check()) ans = min(ans, arr[ri-1].x - arr[le].x);

        pop(le);

    }

    cout << ((ans == 0x3f3f3f3f) ? -1 : ans) << endl;

    return 0;
}