#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

typedef struct {

    int n_18;
    int n_21;
    int n_25;

} num;

map < tuple<int, int, int> , int> MP, visited;

int ans;

signed main() {

    int n;
    cin >> n;
    
    deque <num> dq;

    dq.push_back({n, n, n});
    MP[make_tuple(n, n, n)] = 0;
    //visited[make_tuple(n, n, n)] = 1;

    while (dq.size()) {

        int cur_n_18 = dq.front().n_18;
        int cur_n_21 = dq.front().n_21;
        int cur_n_25 = dq.front().n_25;
        int next_n_18, next_n_21, next_n_25;

        dq.pop_front();

        if (cur_n_18 == 0 && cur_n_21 == 0 && cur_n_25 == 0) {

            ans = MP[make_tuple(cur_n_18,cur_n_21,cur_n_25)];
            break;

        }

        //cout << MP[make_tuple(cur_n_18,cur_n_21,cur_n_25)] << endl;

        if (cur_n_18 >= 3) {
            
            next_n_18 = cur_n_18 - 3;
            
            if (next_n_18 < 0) next_n_18 = 0;
            
            if (visited[make_tuple(next_n_18,cur_n_21,cur_n_25)] != 0) {

                continue;
                
            }
            
            MP[make_tuple(next_n_18, cur_n_21, cur_n_25)] = MP[make_tuple(cur_n_18,cur_n_21,cur_n_25)] + 1;
            visited[make_tuple(next_n_18, cur_n_21, cur_n_25)] = 1;

            dq.push_back({next_n_18, cur_n_21, cur_n_25});

        }

        if (cur_n_18 >= 2 && cur_n_21 >= 1) {

            next_n_18 = cur_n_18 - 2;
            next_n_21 = cur_n_21 - 1;

            if (next_n_18 < 0) next_n_18 = 0;
            
            if (visited[make_tuple(next_n_18,next_n_21,cur_n_25)] != 0) {

                continue;

            }
            
            MP[make_tuple(next_n_18,next_n_21,cur_n_25)] = MP[make_tuple(cur_n_18,cur_n_21,cur_n_25)] + 1;
            visited[make_tuple(next_n_18,next_n_21,cur_n_25)] = 1;

            dq.push_back({next_n_18, next_n_21, cur_n_25});

        }

        if (cur_n_18 >= 1 && cur_n_25 >= 1) {

            next_n_18 = cur_n_18 - 1;
            next_n_25 = cur_n_25 - 1;
            
            if (visited[make_tuple(next_n_18,cur_n_21,next_n_25)] != 0) {

                continue;

            }
            
            MP[make_tuple(next_n_18,cur_n_21,next_n_25)] = MP[make_tuple(cur_n_18,cur_n_21,cur_n_25)] + 1;
            
            visited[make_tuple(next_n_18, cur_n_21, next_n_25)] = 1;
            
            dq.push_back({next_n_18, cur_n_21, next_n_25});

        }

        if (cur_n_25 >= 2) {

            next_n_25 = cur_n_25 - 2;

            if (next_n_25 < 0) next_n_25 = 0;

            if (visited[make_tuple(cur_n_18,cur_n_21,next_n_25)] != 0) {

                continue;

            }

            MP[make_tuple(cur_n_18,cur_n_21,next_n_25)] = MP[make_tuple(cur_n_18,cur_n_21,cur_n_25)] + 1;

            visited[make_tuple(cur_n_18,cur_n_21,next_n_25)] = 1;

            dq.push_back({cur_n_18, cur_n_21, next_n_25});

        }

        if (cur_n_21 >= 1 ) {

            next_n_21 = cur_n_21 - 2;
            next_n_18 = cur_n_18 - 1;

            if (next_n_21 < 0) next_n_21 = 0;
            if (next_n_18 < 0) next_n_18 = 0;

            if (visited[make_tuple(next_n_18,next_n_21,cur_n_25)] != 0) {

                continue;

            }

            MP[make_tuple(next_n_18,next_n_21,cur_n_25)] = MP[make_tuple(cur_n_18,cur_n_21,cur_n_25)] + 1;
            
            visited[make_tuple(next_n_18,next_n_21,cur_n_25)] = 1;

            dq.push_back({next_n_18, next_n_21, cur_n_25});

        }

    }  

    cout << ans << endl;

    return 0;

}