#include <iostream>

using namespace std;

int main() {

    int time = 0;
    cin >> time;

    int num = 0;
    for (int i = 0; i < time; i++) {
        cin >> num;

        if ((num - 1) % 3 == 0 || (num + 1 ) % 3 == 0) 
            cout << "First" << endl;

        else cout << "Second" << endl;            

    }

    return  0;
}