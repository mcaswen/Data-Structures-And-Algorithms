#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

ll deal() {

    string line;
    ll sum;

    while (getline(cin, line)) {

        line.erase(line.begin(), find_if(line.begin(), line.end(), [](unsigned char ch) {

            return !isspace(ch);

        }));

        line.erase(find_if(line.rbegin(), line.rend(), [](unsigned char ch) {

            return !isspace(ch);

        }).base(), line.end());

        if (line.empty()) continue;

        istringstream iss(line);

        ll num;

        while (iss >> num) {

            sum += num;

        }

    }

    return sum;

}

template <typename T>
T read(T &x) {
    
    x = 0;
    T f = 1;
    char ch = getchar();

    while (!isdigit(ch)) {

        if (ch == '-') f = -1;
        ch = getchar();

    }

    while (isdigit(ch)) {

        x = 10 * x + ch;
        ch = getchar();

    }

    x *= f;

}
