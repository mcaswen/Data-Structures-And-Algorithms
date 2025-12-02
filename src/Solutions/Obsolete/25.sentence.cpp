#include <iostream>
#include <vector>

using namespace std;

int main() {

char str = 0;
vector <int> arr(4,0);
int cha = 0;
int cha2 = 0;

    while (cin >> str) {

        cha = str - 'a';

        cin >> str;
        cin >> str;
        cin >> str;

        if (str == 'a' || str == 'b'  || str == 'c') {

            cha2 = str - 'a';
            arr[cha] = arr[cha2];

        }   else {

            arr[cha] = str; 

        }

        cin >> str;

        
    }    

    cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;

    return 0;
}