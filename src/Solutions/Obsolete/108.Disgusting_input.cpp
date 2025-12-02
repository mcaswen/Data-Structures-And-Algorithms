#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

signed main() {

   string line;

    while (getline(cin, line)) {

        size_t st = line.find_first_not_of("\t\r\n");
        size_t ed = line.find_last_not_of("\t\r\n");

        if (st != string::npos && ed != string:: npos) {

            line = line.substr(st, ed - st + 1);

            stringstream ss(line);

            int num, sum = 0;

            while (ss >> num) {

                sum += num;

            }

            cout << sum << endl;

        } else {

            break;

        }

    }

    return 0;
}