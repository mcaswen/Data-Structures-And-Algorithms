#include <iostream>
#include <vector>

int arr[35] = {0,1,2,1,2,3,
                1,2,3,2,1,
                2,2,2,3,1,
                2,3,2,3,2,
                2,3,3,3,2,
                3,3,3,4,2};


using namespace std;

int main() {

    int t;
    cin >> t;
    for (; t; t--) {

        long long num1;

        cin >> num1;
        int sum1,sum2,sum;
        int temp;

        temp = num1 % 15;
        int ans = num1 / 15;

         sum1 = ans + arr[temp];
         sum2 = ans - 1 + arr[temp + 15];
         
         
         if (num1 > 15) {
            sum = (sum1 <= sum2 ? sum1 : sum2);
         }
        
        else sum = sum1;
        
        cout << sum << endl;


    }

    return 0;
}