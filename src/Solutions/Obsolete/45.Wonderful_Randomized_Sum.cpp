#include <iostream>
#include <vector>

using namespace std;

vector <int> arr(200000, 0);
vector <long long> sum1(200000, 0);
vector <long long> sum2(200000, 0);

int main() {


    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {

        int num;
        cin >> num;

        arr[i] = num;

        sum1[i] = sum1[i-1] + arr[i];

    }

    sum2[n] = arr[n];

    for (int i = n-1; i >= 1; i--) {

        sum2[i] = sum2[i+1] + arr[i];

    }

   int temp = 0;
   long long max1 = 0;
   long long max2 = 0;

    for (int i = 1; i <= n; i++) {

        if (sum1[i] < 0 && -sum1[i] >= max1) {
            max1 = -sum1[i];
            temp = i;
        
        }
    
    }

    if (temp == n)
        max2 = 0;


    for (int i = n; i > temp; i--) {

        if (sum2[i] < 0 && -sum2[i] >= max2) {
            max2 = -sum2[i];
        }

    }

    int temp2 = n+1;
    long long max3 = 0;
    long long max4 = 0;
    
    for (int i = n; i >= 1; i--) {

        if (sum2[i] < 0 && -sum2[i] >= max3) {
            max3 = -sum2[i];
            temp2 = i;       

        }

    }
    
    if (temp2 == 1)
        max4 = 0;

        for (int i = 1; i < temp2; i++) {

            if (sum1[i] < 0 && -sum1[i] >= max4) {
                max4 = -sum1[i];
            
            }
        
        }
    
    long long re1 = sum1[n] + 2 * max1 + 2 * max2;
    long long re2 = sum1[n] + 2 * max3 + 2 * max4;
    
    if (re1 >= re2)
        cout << re1 << endl;
    else 
        cout << re2 << endl;
    


    return 0;
}
