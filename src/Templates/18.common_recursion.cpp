#include <iostream>
#include <unordered_set>
#include <stack>
#include <algorithm>

using namespace std;

#define INF 0x3f3f3f3f

unordered_set <string> str_set1;
string str;

//返回一个字符串的所有字串，无剪枝
void str_permutation1(string s, int i, int str_len) {

    if (i == str_len) str_set1.insert(s);
    
    s.push_back(str[i]);
    str_permutation1(s, i+1, str_len);

    //回溯后继续决定
    s.pop_back();
    str_permutation1(s, i+1, str_len);

}

unordered_set <string> str_set2;

void str_permutation2(string s,int i, int size, int str_len) {

    if (i == str_len) str_set2.insert(s.substr(0, size));

    s[size] = str[i];

    //利用size决定是否加入当前字符
    str_permutation2(s, i+1, size, str_len);
    str_permutation2(s, i+1, size+1, str_len);

}

vector <int> ans(15, 0);
vector <vector <int> > anses;
vector <int> arr;
//返回一个序列中所有元素的组合，顺序任意

void find3(int i, int n, int size) {

    if (i == n) {
        
        anses.push_back(ans);

    } else {

        int j = i + 1;
        //区间i - j:包含一个元素的所有重复元素

        while (j < n && arr[i] == arr[j]) {

            j++;

        }

        //选0个该重复元素
        find3(j, n, size);

        for (; i < j; i++) {

            //选i' - i个重复元素
            ans[size++] = arr[i];
            find3(j, n, size);

        }
    
    }

}

vector <vector <int> > num_combination() {

    //排序确保一个元素的所有重复元素紧挨
    sort(arr.begin(), arr.end());
    int n = arr.size();

    find3(0, n, 0);

    return anses;

}

//返回一个无重复元素数组的全排列

void arr_swap(int i, int j) {

    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;

}

void permute(int i, int len) {

    if (i == len) {

        vector <int> cur;
        for (int k = 0; k < len; k++) {

            cur.push_back(arr[k]);

        }

        anses.push_back(cur);

    } else {

        unordered_set <int> sset;//对有重复元素数组的处理

        for (int j = i; j < len; j++) {
            
            if (sset.find(arr[j]) == sset.end()) {//若j超过第二次以上与i位置互换，则跳过该路径
                
                sset.insert(arr[j]);
                //第一次交换后开始下一级递归
                arr_swap(i, j);
                permute(i + 1, len);
                //交换回去
                arr_swap(i, j);
            
            }
        }

    }

}

//利用递归反转一个栈
stack <int> stk;

int getbottom() {

    int ans = stk.top();
    stk.pop(); 

    if (stk.empty()) {

        return ans; //底部元素

    } else {

        int last = getbottom();
        stk.push(ans);

        return last;

    }

}

void reverse() {

    if (stk.empty()) {

        return;

    } else {

        int bot = getbottom();
        reverse();
        stk.push(bot);

    }

}

//用递归完成一个栈的排序（从栈底到栈顶，大->小）
int fdeep() {

    if (stk.empty()) return 0;

    int num = stk.top();
    stk.pop();
    
    int deep = fdeep() + 1;
    stk.push(num);

    return deep;

}

int fmax(int deep) {

    if (!deep) return -INF;

    int num = stk.top();
    stk.pop();

    int rest_max = fmax(deep - 1);
    int mmax = max(rest_max, num);

    stk.push(num);
    return mmax;

}

int ftime(int deep, int mmax) {

    if (!deep) return 0;

    int num = stk.top();
    stk.pop();

    int rest_times = ftime(deep - 1, mmax);
    rest_times  += ((num == mmax) ? 1 : 0);
    
    stk.push(num);
    return rest_times;

}

void done(int deep, int mmax, int times) {

    if (!deep) {

        while (times--) {

            stk.push(mmax);

        }

        return;

    }

    int num = stk.top();
    stk.pop();

    done(deep - 1, mmax, times);

    if (num != mmax) {

        stk.push(num);

    }

}

void stk_sort() {

    int depth = fdeep();

    int mmax = fmax(depth);

    int times = ftime(depth, mmax);

    while (depth) {

        mmax = fmax(depth);
        times = ftime(depth, mmax);

        done(depth, mmax, times);
        depth -= times;

    }

}

//汉诺塔问题,打印最优移动轨迹

string loc[3] = {"左", "中", "右"};

void move(int n, int from, int to, int other) {

    if (n == 0) return;

    move(n-1, from, other, to);

    cout << n << " from " << loc[from] << " move to " << loc[to] << endl;

    move(n-1, other, to, from);

}

int main() {

    move(100, 0, 2, 1);

}