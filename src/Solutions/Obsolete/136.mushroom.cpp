#include <iostream>

typedef long long ll;
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int ldx[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
int ldy[8] = {1, -1, 1, -1, -1, 1, 0, 0};

vector <vector <char> > arr(1005, vector<char>(1005, 0));
vector <vector <int> > saf(1005, vector<int>(1005, 1));
vector <vector <int> > vis(1005, vector<int>(1005, 0));
int n, m;
void dfs() {
    
    deque <pair <int, int> >dq;
    dq.push_back(make_pair(1, 1));
    vis[1][1] = 1;
    int i = 1;
    int j = 1;
    
    int cnt = 0;
    bool found = false;
    while (dq.size()) {
        bool Flag = true;
        pair <int, int> f = dq.front();
        i = f.first;
        j = f.second;
        
        if (f.first == n && f.second == m) {
            found = true;
            cout << cnt << endl;
            break;
            
        }
        
        dq.pop_front();
        
        for (int k = 0; k < 4; k++) {
            //if (f.first == 2 && f.second == 1) cout << i + dx[k] << " " << j + dy[k] << endl;
             if (!(i + dx[k] < 1 || i + dx[k] > n || j + dy[k] < 1 || j + dy[k] > m || 
             saf[i + dx[k]][j + dy[k]] == 0 || vis[i + dx[k]][j + dy[k]] == 1)) {
                Flag = false;
                 dq.push_back(make_pair(i + dx[k], j + dy[k]));
                vis[i + dx[k]][j + dy[k]] = 1;
                 //cout << i + dx[k] << " " << j + dy[k] << endl;
                 
             }
        }
        
        if (!Flag) cnt++;
        
    }
    
    if (!found) cout << -1 << endl;
    
}

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) {
            
            cin >> arr[i][j];
            if (arr[i][j] == '*') {
                
                saf[i][j] = 0;
               for (int k = 0; k < 4; k++) {
                   
                   if (!(i + dx[k] < 1 || i + dx[k] > n || j + dy[k] < 1 || j + dy[k] > m ))
                   
                    saf[i + dx[k]][j + dy[k]] = 0;
                  
               }
                
            }
            if (arr[i][j] == '#') {
                saf[i][j] = 0;
                for (int k = 0; k < 8; k++) {
                   
                    if (k < 4) {
                        if (!(i + 2 * dx[k] < 1 || i + 2 * dx[k] > n || j + 2 * dy[k] < 1 || j + 2 * dy[k] > m ))
                        
                        saf[i + 2 * dx[k]][j + 2 * dy[k]] = 0;
                    }
                    
                    if (!(i + ldx[k] < 1 || i + ldx[k] > n || j + ldy[k] < 1 || j + ldy[k] > m ))
                     saf[i + ldx[k]][j + ldy[k]] = 0;
                  
               }
                
            }
            
        }
    
    dfs();
    
}