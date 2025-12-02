#include <iostream>
#include <vector>

using namespace std;

vector <int> arr(100, 0);
vector <int> pos(100, 0);
vector <int> used(100, 0);


void printSubset(int n, vector <int> &pos ,int cur) //增量构造法
{

    for (int i = 0; i < cur; i++) {

        cout << arr[pos[i]] << " ";

    }
    
    int st = cur ? (pos[cur-1] + 1) : 0;

    for (int i = st; i < n; i++) {

        pos[cur] = i;
        printSubset(n, pos, cur + 1);

    }

}

void printSubset2(int n, vector <int> &used, int cur) //位向量法
{ 

    if (cur == n) {
        for (int i = 0; i < n; i++) {
            if (!used[i])
                cout << arr[i] << " ";

        }

        cout << endl;
        return;

    }

    used[cur] = 0;
    printSubset2(n, used, cur + 1);

    used[cur] = 1;
    printSubset2(n, used, cur + 1);

}

void printSubset3(int n, int seq) //二进制法
{ 

    for (int i = 0; i < n; i++) {

        if (seq & (1 << i) )
            cout << arr[i] << " ";

    }

    cout << endl;
    
}


signed main() {

    int n;
    cin >> n;

    for (int i = 0; i <= n; i++) {

        arr[i] = i + 1;

    }

    int cur = 0;

    //printSubset(n, pos, cur);
    //printSubset2(n, used, cur);

    for (int i = 0; i < (1 << n); i++) {

        printSubset3(n, i);

    }

    return 0;
}

