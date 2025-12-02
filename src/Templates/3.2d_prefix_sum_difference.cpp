#include <iostream>
#include <vector>

using namespace std;

const int MAXSIZE = 1000;

vector < vector <int> > arr(MAXSIZE, (vector <int>(MAXSIZE, 0)));
vector < vector <int> > sum(MAXSIZE, (vector <int>(MAXSIZE, 0)));
vector < vector <int> > brr(MAXSIZE, (vector <int>(MAXSIZE, 0)));
vector < vector <int> > crr(MAXSIZE, (vector <int>(MAXSIZE, 0)));

void twod_perfix_sum() {

    int n = 10;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cnt++;    
            arr[i][j] = cnt;
            sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + arr[i][j];
            //cout << sum[i][j] << "\t";

        }

        //cout << endl;    
    
    }

    //int x1,y1,x2,y2;
    //cin >> x1 >> y1 >> x2 >> y2;

    //int sumxy = sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1]; //左上角为（x1,y1),右下角为(x2,y2)的矩形面积公式



}

void twod_difference() {

    int n = 10;
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j<= n; j++) {
        
            brr[i][j] = arr[i][j] - arr[i-1][j] - arr[i][j-1] + arr[i-1][j-1];
            //cout << brr[i][j] << '\t';

        }
   
        //cout << endl;
    }

}

void twod_addsome() {

    int c;
    cin >> c;

    int x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    brr[x1][y1] += c;
    brr[x1][y2+1] -= c;
    brr[x2+1][y1] -= c;
    brr[x2+1][y2+1] += c; //x1,y1 x2,y2的矩形中每个点的数值加c

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j<= 10; j++) {
        
            crr[i][j] = crr[i-1][j] + crr[i][j-1] - crr[i-1][j-1] + brr[i][j]; //将差分数组重新整合为原数组
            cout << crr[i][j] << '\t';

        }
   
        cout << endl;
    }


}

int main() {

    twod_perfix_sum();
    twod_difference();
    twod_addsome();

    return 0;
}