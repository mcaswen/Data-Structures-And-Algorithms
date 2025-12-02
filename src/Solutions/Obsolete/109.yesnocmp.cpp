#include <iostream>
#include <cstring>

using namespace std;

signed main() {

    long long a, b;
    cin >> a >> b;
    cin.ignore();

    if ( (a >= 0 && b >= 0) || (a < 0 && b < 0)) {

        string line;

        cin >> line;

        for (int i = 0; i < line.size(); i++) {

            if (isupper(line[i])) {

                line[i] += 32;

            }

        }

        if (line == "yes") cout << "ok" << endl;
        else cout << "wa" << endl;


    } else {

        string line;

        cin >> line;

        for (int i = 0; i < line.size(); i++) {

            if (isupper(line[i])) {

                line[i] += 32;

            }

        }

        if (line == "no") cout << "ok" << endl;
        else cout << "wa" << endl;

    }

    return 0;
}