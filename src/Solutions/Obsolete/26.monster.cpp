#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n, m, k;

    cin >> n;
    vector < vector<int> > arr(n, vector<int>(n, 0));
    
    cin >> m;
    cin >> k;
    
    for (int i = 0; i < m; i++) {

        int x,y;    
        
        cin >> x;
        cin >> y;

        x--;
        y--;

        arr[x][y] = 1;

        if (x - 2 >= 0)
            arr[x-2][y] = 1;

        if (x + 2 < n)
            arr[x+2][y] = 1;

        if (x - 1 >= 0) {
            for (int j = y - 1; j <= y + 1; j++) {
                if (j >= 0 && j < n)
                    arr[x-1][j] = 1;
            }
        }

        for (int j = y - 2; j <= y + 2; j++) {
            if (j >= 0 && j < n)
                arr[x][j] = 1;
        }

        if (x + 1 < n) {
            for (int j = y - 1; j <= y + 1; j++) {
                if (j >= 0 && j < n)
                    arr[x+1][j] = 1;
            }
        }
    }

    for (int i = 0; i < k; i++) {
        
        int x,y;

        cin >> x;
        cin >> y;

        x--;
        y--;

        for (int j = x - 2; j <= x + 2; j++) {
            for (int z = y - 2; z <= y + 2; z++) {
                if (z < n && z >= 0 && j < n && j >= 0) {
                    arr[j][z] = 1;
                }
            }
        }
    }
    
    int sum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0) {
                
                sum++;
            }
        }
    }

    cout << sum << endl;

    return 0;
}
