#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {

    int n = 0;
    cin >> n;

    vector <int> arr(n, 0);

    int sco = 0;
    int min = 0;int max = 0;
    int ismin = 0;

    for (int i = 0; i < n; i++) {

        cin >> sco;

        arr[i] = sco;
        
        if (ismin == 0) {
        min = arr[i];
        ismin = 1;
        
        }
        
        if (arr[i] <= min)
            min = arr[i];

        if (arr[i] >= max)
            max = arr[i];

    }

    int sum = 0;

    ismin = 0;
    int ismax = 0;
    int j = 0;
    int sur = n - 2;
    for (; j < n; j++) {

        if (arr[j] == max && ismax == 0) {
            arr[j] = 0;
            ismax = 1;    
        }

        if (arr[j] == min && ismin == 0) {
            arr[j] = 0;
            ismin = 1;    

        }
        sum += arr[j];


    }

    double ave = sum * 1.0 / sur;

    cout << fixed << setprecision(2) << ave << endl;

    return 0;
}