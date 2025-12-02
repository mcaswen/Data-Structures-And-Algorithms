#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector < vector <int> > Map(35, vector <int> (35, -1));

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
deque <pair <int, int> > bfs_dq, re_dq;
int n, st_x, st_y;
bool illegal = false;

void bfs(int i, int j, vector < vector <int> > visited_map) {
    
    bfs_dq.push_back(make_pair(i, j));
    re_dq.push_back(make_pair(i, j));
    //cout << i << " "  << j << endl;
    visited_map[i][j] = -1;

    while (!bfs_dq.empty()) {

        int x = bfs_dq.front().first;
        int y = bfs_dq.front().second;

        bfs_dq.pop_front();

        int cx, cy;

        for (int k = 0; k < 4; k++) {

            cx = x + dx[k];
            cy = y + dy[k];
            //if (cx == 3 && cy == 11) cout << st_x << " " << st_y << endl;
            
            if (cx < 1 || cx > n || cy < 1 || cy > n || Map[cx][cy] == 1) {
                
                //visited_map[cx][cy] = -1;
                //if (x == 3 && y == 4) cout << cx << " " << cy << endl;
                continue;

            }

            else {

                if (cx <= 1 || cx >= n || cy <= 1 || cy >= n) {
                    
                    //if (st_x == 3 && st_y == 4) cout << cx << " " << cy << endl;

                    visited_map[cx][cy] = -1;
                    illegal = true;

                    break;

                }

                if (visited_map[cx][cy] == -1) {
                    //if (x == 3 && y == 4) cout << cx << " " << cy << endl;
                    continue;

                }

                //if (x == 3 && y == 4) cout << cx << " " << cy << endl;

                bfs_dq.push_back(make_pair(cx, cy));
                re_dq.push_back(make_pair(cx, cy));
                
                visited_map[cx][cy] = -1;

            }
        }
        
        if (illegal) break;

    }

}

signed main() {

    cin >> n;

    //cin.ignore();

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {

            cin >> Map[i][j];

        }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            
            //cout << i << " " << j << endl;

            //cout << visited_map[i][j]  << " " << Map[i][j] << endl;

            if ( Map[i][j] == 0) {

                vector < vector <int> > visited_map(35, vector <int> (35, 0));

                //cout << i << " " << j << endl;
                st_x = i; st_y = j;
                re_dq.clear();
                bfs_dq.clear();
                illegal = false;
                bfs(i, j, visited_map);

                if (!illegal) {

                    for (auto p: re_dq) {

                        Map[p.first][p.second] = 2;
    
                    }
                    break;

                }

            }
            
        }
    
        //if (!illegal) break;
    
    }
    
    //cout << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            cout << Map[i][j] << " ";

        }

        cout << endl;

    }
        
    return 0;
}
