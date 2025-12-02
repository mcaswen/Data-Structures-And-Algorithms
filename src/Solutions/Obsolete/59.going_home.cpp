#include <iostream>
#include <vector>

using namespace std;

vector < vector <int> > squ(1005, vector <int> (1005, 0));

int main() {

    int N, M;
    cin >> N >> M;

    for (; M; M--) {
        
        int x,y;
        cin >> x >> y;

        squ[x][y] = -1;

    }

    squ[1][1] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i - 1 >= 1 && squ[i-1][j] != -1 && squ[i][j] != -1)
                squ[i][j] = (squ[i-1][j] + squ[i][j]) % 100003;

            if (j - 1 >= 1 && squ[i][j-1] != -1 && squ[i][j] != -1)
                squ[i][j] = (squ[i][j-1] + squ[i][j]) % 100003;

        }
    }

    cout << squ[N][N] << endl;

    return 0;
}