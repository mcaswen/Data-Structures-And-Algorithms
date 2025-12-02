#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
vector <int> mp = vector <int>(32, -2);

int findTheLongestSubstring(string s) {
    
    mp[0] = -1;
    int ans = 0;

    for (int i = 0, sum = 0; i < s.size(); i++) {

        int m = move(s[i]);

        if (m != -1) 
            sum ^= (1 << m);
        
        if (mp[sum] != -2) {

            ans = max(ans, i - mp[sum]);

        } else {

            mp[sum] = i;

        }

    }

    return ans;

}

int move(char c) {

    switch (c)
    {
    case 'a': return 0;
    case 'e': return 1;
    case 'i': return 2;
    case 'o': return 3;
    case 'u': return 4;
        
    default: return -1;
        
    }

    return -1;

}