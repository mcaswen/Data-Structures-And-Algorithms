#include <iostream>
#include <vector>

using namespace std;

vector <vector <char> > map(1000, vector <char>(1000, '0'));

vector <char> key(5, 0);
vector <char> curkey(5, 0);
string ope;
int ans;
int xstart, ystart, m, n;

void check(int &x, int &y, int idx, int &isbroken, int &isend) {

    switch (curkey[idx])
    {
    case 'L':
        
        y -= 1;
        
        break;
    
    case 'R':
       
        y += 1;
       
        break;

    case 'U':

        x -= 1;
        
        break;

    case 'D':
            
        x += 1;
        
        break;

    }

    if (map[x][y] == '#' || x > n || x < 1 || y > m || y < 1)
        isbroken = 1;

    else if (map[x][y] == 'E')
        isend = 1;

}

void permutation(int cur) {

    if (cur > 4) {

        int x = xstart;
        int y = ystart;
        int isbroken = 0;
        int isend = 0;

        /*for (int i = 0; i <= 4; i++) {

            cout << curkey[i] << " ";

        }*/

        cout << endl;

        for (int i = 0; i < ope.length(); i++) {

            int idx = ope[i] - '0' + 1;
            check(x, y, idx, isbroken, isend);
            //cout << x << " " << y << endl; 
            
            if (isbroken) 
                //cout << 1 << endl;
                break;

            if (isend) {    
                
                ans++;
                break;

            }

        }

        return;
    }

    else {

        for (int i = 1; i <= 4; i++) {

            int Aflag = 0;

            for (int j = 1; j < cur; j++) {
                if (curkey[j] == key[i]) {

                    Aflag = 1;
                    break;

                }
            }     
            
            if (!Aflag) {

                curkey[cur] = key[i];
                permutation(cur+1);

            }
        }
    }
}


int main() {

    key[1] = 'L'; key[2] = 'R'; key[3] = 'U'; key[4] = 'D';
    ans = 0;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            cin >> map[i][j];
            
            if (map[i][j] == 'S') {
                
                xstart = i;
                ystart = j;

            }
        }
    }

    cin >> ope;

    int cur = 1;

    permutation(cur);

    cout << ans << endl;

    return 0;
}