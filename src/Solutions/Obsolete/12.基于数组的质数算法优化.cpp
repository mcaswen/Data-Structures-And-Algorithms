#include <iostream>
#include <vector>
#include <cmath>

using namespace  std;

vector <int> prime(10001, 0);

int main() {

    prime[1] = 2;

    int cnt = 1;
    for (int n = 3; n <= 1000; n++) {
        int isprime = 1;
        for (int i = 1; i <= cnt && prime[i] <= sqrt(n); i++) {
            
            if (n % prime[i] == 0) {
                isprime = 0;
                break;

            }
        }
        if (isprime)
            prime[++cnt] = n;
    }    


    for (int i = 1; i <= cnt; i++)
        cout << prime[i] << " ";

    return 0;
}