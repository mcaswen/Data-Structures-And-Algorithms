#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
vector <int> pos(20, 0);

int n, ans;

void findSubset(int cur) {

    if (cur == 3) {

        int sum = 0;
        
        int a = pos[0];
        int b = pos[1];
        int c = pos[2];
        
        if (a == b + c) {

            if (arr[a] + arr[b] + arr[c] + 4 == n) {

                if (b == c)
                    ans++;

                else    
                    ans += 2;

            }


        }
        
        if (b == a + c) {

            if (arr[a] + arr[b] + arr[c] + 4 == n) {

                if (a == c)
                    ans++;

                else    
                    ans += 2;

            }


        }
        
        if (c == a + b) {

            if (arr[a] + arr[b] + arr[c] + 4 == n) {

                if (a == b)
                    ans++;

                else    
                    ans += 2;

            }


        }
    
    
    }

    int st = cur ? pos[cur-1] + 1 : 0;

    for (int i = st; i < 10; i++) {

        pos[cur] = i;
        findSubset(cur + 1);

    }

}

signed main() {
   

        cin >> n;

        int cur = 0;
        ans = 0;

        findSubset(cur);

        cout << ans << endl;


    return 0;
}