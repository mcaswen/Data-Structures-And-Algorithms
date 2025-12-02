#include <iostream>
#include <vector>

using namespace std;

vector <int> arr(1e7, 0);
vector <int> num(25, 0);
vector <int> pos(25, 0);

int n, k, cnt, ans;

int checkarr(int num) {

    int isfound = 0;


    if (num < arr[cnt]) {

        for (int i = 1; i <= cnt; i++) {

            if (num == arr[i]) {

                isfound = 1;
                break;

            }

        }

    }
    
    else {
    
        for (int i = 2; i <= num; i++) {
            
            int isprime = 1;

            for (int idx = 1; idx <= cnt; idx++) {
                
                if (i % arr[idx] == 0 && i != arr[idx]) {

                    isprime = 0;
                    break;

                }

            }

            if (isprime) {

                cnt++;
                arr[cnt] = i;
            
                if (num == i)
                    isfound = 1;
                       
            }

        }
    
    }
    
    return isfound;

}

void findsubset(int cur) {

    if (cur == k) {
        
        int sum = 0;

        for (int i = 0; i < cur; i++) {

            sum += num[pos[i]];

        }

        if (checkarr(sum))
            ans++;

    }

    int st = cur ? pos[cur-1] + 1 : 0;

    for (int i = st; i < n; i++) {

        pos[cur] = i;
        findsubset(cur + 1);

    }

    return;

}

signed main() {

    arr[1] = 2;

    cin >> n >> k;
    cnt = 1;
    ans = 0;

    for (int i = 0; i < n; i++) {

        cin >> num[i];

    }

    int cur = 0;

    findsubset(cur);

    cout << ans << endl;

    return 0;
}