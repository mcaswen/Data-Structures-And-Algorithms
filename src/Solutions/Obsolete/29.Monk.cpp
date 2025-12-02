#include <iostream>
#include <vector>

using namespace std;

int main() {

    int time = 0;
    cin >> time;

    for (; time; time--) {

        int number, length;
        cin >> length;
        cin >> number;


        vector <int> arr(number, 0);

        int max = 0;    
        for (int i = 0;i < number; i++) {

            cin >> arr[i];
            if (arr[i] > max) max = arr[i];
        }

        int sum = 0;
        int ismax = 1;
        for (int j = 0; j < number; j++) {
            if (arr[j] == max && ismax == 1) {
                ismax = 0;
                continue;    

            }    

            sum += (2 * (arr[j]) - 1);

        }

    cout << sum << endl;

    }



    return 0;
}