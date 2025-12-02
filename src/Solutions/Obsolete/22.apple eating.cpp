#include <iostream>

using namespace std;

int main() {

    int number = 0;

    cin >> number;

    if (number == 0 || number == 1) 
        cout << "Today, I ate " << number << " apple.";

    else cout << "Today, I ate " << number << " apples.";



    return 0;
}