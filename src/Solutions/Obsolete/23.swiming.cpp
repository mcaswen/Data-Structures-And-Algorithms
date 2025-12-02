#include <iostream>

using namespace std;

int main() {

    float s = 0;
    cin >> s;

    float sum = 2;
    int cnt = 1;
    float pace = 2;

    while (sum < s) {

        pace = pace * 0.98;
        sum += pace;
        cnt++;

    }

    cout << cnt;


    return 0;
}