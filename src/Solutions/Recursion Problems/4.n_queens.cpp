//leetcode 52
#include <iostream>
#include <cmath>
using namespace std;

bool check(vector <int>& path, int i, int j) {

    //k: 0 ~ i - 1行
    //path[k]: 第k行的皇后在第几列
    for (int k = 0; k < i; k++) {
        //如果之前行的皇后和当前皇后在同一列     当前行 - 之前行 == 当前列 - 之前列
        if (path[k] == j || abs(i - k) == abs(j - path[k])) {

            return false;

        }

    }

    return true;

}

int f1(vector <int>& path, int i, int n) {

    if (i == n) return 1;

    int ans = 0;

    //i为行， j为列
    for (int j = 0; j < n; j++) {

        if (check(path, i, j)) {

            path[i] = j;
            ans += f1(path, i + 1, n);

        }

    }

    return ans;

}

int main() {

    int n;
    cin >> n;
    vector <int> path(n + 5, 0);

    cout << f1(path, 0, n);

}