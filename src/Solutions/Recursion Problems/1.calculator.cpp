#include <vector>

using namespace std;

int where;
string s;

void push(vector <int>& nums, vector <int>& ops, int cur, char op) {

    int n = nums.size();

    if (!n || ops[n-1] == '-' || ops[n-1] == '+') {

        nums.push_back(cur);
        ops.push_back(op);

    } else {

        int res = (ops[n-1] == '*') ? nums[n-1] * cur : nums[n-1] / cur;
        
        nums[n-1] = res;
        ops[n-1] = op;
    
    }

}

int compute(vector <int>& nums, vector <int>& ops) {

    int ans = nums[0];  
    int n = nums.size();

    for (int i = 1; i < n; i++) {

        ans += (ops[i-1] == '+') ? nums[i] : -nums[i];

    }

    return ans;

}

int f(int i) {  

    int cur = 0;

    vector <int> nums;
    vector <int> ops;

    while (i < s.size() && s[i] != ')') {

        if (s[i] >= '0' && s[i] <= '9') {

            cur = cur * 10 + s[i++] - '0';

        } else if (s[i] != '(') {

            push(nums, ops, cur, s[i++]);
            cur = 0;

        } else {

            cur = f(i + 1);
            i = where + 1;

        }

    }

    push(nums, ops, cur, '+');
    where = i;
    return compute(nums, ops);

}