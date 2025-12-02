#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector < vector <int> > squ(101, vector <int> (101, 0));

int main() {

    int n;
    cin >> n;

    for (; n; n--) {

        int a,b;
        cin >> a >> b;

        squ[a][b] += 1;

    }

    for (int i = 1; i <= 100 ; i++) {
        for (int j = 1; j <= 100; j++) {
            squ[i][j] += squ[i-1][j] + squ[i][j-1] - squ[i-1][j-1];
        }
    }
    
    int ans = 0;

    //边界个数即为xyab矩形中包含的个数减去小一号的矩形中包含的个数
    for (int x = 1; x <= 99; x++) {
        for (int y = 1; y <= 99; y++) {
            for (int a = x + 1; a <= 100; a++) {
                for (int b = y + 1; b <= 100; b++) {
                    
                    int sum1 = squ[a][b] - squ[a][y-1] - squ[x-1][b] + squ[x-1][y-1];//大矩形

                    int sum2 = squ[a-1][b-1] - squ[a-1][y] - squ[x][b-1] + squ[x][y];//小矩形

                    ans = max(ans, sum1-sum2);
                
                
                }
            }
        }
    }
    
    cout << ans << endl;

    return 0;
}