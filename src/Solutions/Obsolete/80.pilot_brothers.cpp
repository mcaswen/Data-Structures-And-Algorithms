#include <iostream>
#include <vector>

using namespace std;

string str[10];
vector < vector<int> > arr(10, vector <int> (10, 0));
vector < vector<int> > curarr(10, vector <int> (10, 0));

vector < pair<int, int> > ans;


void init() {

    for (int i = 1; i <= 4; i++) {
        
        cin >> str[i];
        
        for (int j = 0; j < 4; j++) {
            if (str[i][j] == '-')
                arr[i][j+1] = 1;
            
            else 
                arr[i][j+1] = 0;

        }

    }

    return;

}

void copy() {

    for (int i = 1; i <= 4; i++) 
        for (int j = 1; j <= 4; j++)
            curarr[i][j] = arr[i][j];

    return;
}

int check() {

    //cout << 1 << endl;

    for (int i = 1; i <= 4; i++) 
        for (int j = 1; j <= 4; j++) {
            if (curarr[i][j] == 0)
                
                return 0;
        
        }


    return 1;

}

void searchSubset() {

    for (int i = 0; i <= (1 << 16) - 1; i++) {
        copy();
        ans.clear();

        for (int j = 0; j < 16; j++) {

            if ((i & (1 << j)) == 0) {
                
                //cout << 1 << endl;
                
                continue;
            }
            int x = j / 4 + 1;
            int y = j % 4 + 1;

            for (int k = 1; k <= 4; k++) {

                curarr[x][k] ^= 1;
                curarr[k][y] ^= 1;

            }

            curarr[x][y] ^= 1;
            ans.push_back({x, y});

        }

        if (check()) {

            //cout << 1 << endl;

            cout << ans.size() << endl;

            for (auto p : ans) {

                cout << p.first << " " << p.second << endl;

            }

            return;

        }

    }

}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    //cout << 1 << endl;

    int ac;

    init();

    searchSubset();

    return 0;
}