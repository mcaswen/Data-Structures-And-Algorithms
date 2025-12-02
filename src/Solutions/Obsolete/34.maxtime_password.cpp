#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector <char> arr(11, 0);

int main() {

    int t;
    cin >> t;
    cin.ignore();
    for (int a = 0; a < t; a++) {


        string n;
        int i = 0;
        int j = 0;
        
        int isend = 0;
        char alt = 0;

        getline(cin , n);
        

        for (;i < n.length(); i++)      
            arr[i] = n[i];

        if (i == 1) {
            
            if (islower(arr[0] + 1))
                arr[1] = arr[0] + 1;
            
            else arr[1] = arr[0] - 1;
        }

        else {
        
            
            for (; j < i; j++) {
            
                if (arr[j-1] == arr[j]) {

                    
                    alt = arr[j];

                    if (islower(arr[j] + 1))
                        arr[j] = arr[j] + 1;
            
                    else arr[j] = arr[j] - 1;

                    break;
                }      

                if (j == i - 1) {

                    if (islower(arr[j] + 1))
                        arr[j+1] = arr[j] + 1;
            
                    else arr[j+1] = arr[j] - 1;    

                    isend = 1;
                    
                    break;
                
                }
            }
        
            if (!isend) {

                for (int k = i - 1; k >= j + 1; k--) {

                    arr[k+1] = arr[k];

                }

                arr[j+1] = alt;

            }
              
        }

        int l = 0;

        for (; l < i + 1; l++) {

            cout << arr[l];

        }

        cout << endl;

    }

    return 0;
}