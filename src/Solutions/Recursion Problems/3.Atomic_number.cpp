//leetcode 726
#include <iostream>
#include <map>

using namespace std;

string s;
int where;

map <string, int> uni(map <string, int> a, map <string, int> b) {

    map <string, int> mp = a;

    for (const auto& [key, value]: b) {

        mp[key] += value;

    }

    return mp;

}

map <string, int> f(int i) {

    map <string, int> mp;
    string ele; 
    int cur = 0;

    while (i < s.size() && s[i] != ')') {

        if (isupper(s[i])) {

            ele += s[i];
            int j = i + 1;

            for (; j < s.size() && islower(s[j]); j++) {

                ele += s[j];

            } 

            mp[ele] += 1;
            //cout << ele << " " << mp[ele] << endl;
            if (!isdigit(s[j])) ele = "";
            if (isdigit(s[j])) mp[ele]--;
            
            i = j;

        } else if (isdigit(s[i])) {

            int j = i;
            for (; j < s.size() && isdigit(s[j]);) {

                cur = cur * 10 + s[j++] - '0';

            } 
            
            //mp[ele] = 1;
            
            mp[ele] += cur;
            //cout << ele << " " << cur << endl;
            
            cur = 0;
            ele = "";
            
            i = j;

        } else {

            mp = uni(mp, f(i+1));
            i = where;

        }

    }

    int idx = i + 1;
    int num = 0;
    while (idx < s.size() && isdigit(s[idx])) {

        num = num * 10 + s[idx++] - '0';

    }
    
    if (num != 0) {
        for (const auto& [k, v] : mp) {

            mp[k] = num * mp[k];

        };
    }
    
    where = idx;

    return mp;

}

int main() {

    cin >> s;

    map <string, int> mp = f(0);
    string ans;

    for (auto& [k, v] : mp) {

        ans += k;
        ans += (v > 1 ? to_string(v) : "");
    }

    cout << ans;

}