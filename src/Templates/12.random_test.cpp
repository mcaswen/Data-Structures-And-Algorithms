#include <iostream>
#include <cstdlib>

#define MAX 1e9

using namespace std;

int random_num() {

    double n = rand();

    return (n / RAND_MAX) * MAX; 

}

signed main() {

    srand(time(NULL));

}