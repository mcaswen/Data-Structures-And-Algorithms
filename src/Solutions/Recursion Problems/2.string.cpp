//leetcode 394

#include <iostream>
#include <cstring>

using namespace std;

string s;
string ans;
int where;

string fsub(string sub, int num) {

    //cout << sub << " " << num << endl;
    if (num == 0) num = 1;

    string sub2;

    for (int i = 0; i < num; i++) {

        sub2 += sub;

    }

    return sub2;

};

string f(int i, int num) {
    //cout << 1;
    string sub;
    int cur = 0;

    while (i < s.size() && s[i] != ']') {

        if (isdigit(s[i])) {

            cur = cur * 10 + s[i++] - '0';
            
        }

        else if (islower(s[i])){

            sub.push_back(s[i++]);

        } else {

            sub += f(i+1, cur);
            cur = 0;
            i = where + 1;

        }

    }

    sub = fsub(sub, num);
    where = i;
    //ans += sub;

    return sub;

}

int main() {

    cin >> s;

    string ans = f(0, 0);

    cout << ans << endl;

    return 0;

}