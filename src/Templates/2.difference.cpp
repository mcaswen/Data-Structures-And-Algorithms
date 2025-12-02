#include <iostream>
#include <vector>

using namespace std;
const int MAXSIZE = 100000;

vector <int> arr(MAXSIZE, 0);
vector <int> brr(MAXSIZE, 0);

int main() {

   int n;
   cin >> n;
   
    for (int i = 1; i <= n; i++) {
            
            arr[i] = i;
            brr[i] = arr[i] - arr[i-1];
    }

    int a, b, k;
    cin >> a >> b >> k;

    brr[a] += k;
    brr[b + 1] -= k;
    arr[0] = 0;

    for (int i = 1; i <= n; i++) {
            
        arr[i] = arr[i-1] + brr[i];
        cout << arr[i] << " ";
    
    }

    return 0;
}