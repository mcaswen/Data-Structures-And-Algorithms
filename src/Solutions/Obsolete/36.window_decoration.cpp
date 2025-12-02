#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

vector <vector <int> > arr(100,(vector <int> (100,0)));

int main() 
{

    int time;
    cin >> time;

    double sum = 0;
    for (; time; time--) {

        int x,y;    
        cin >> x >> y;

        if (x <= 99 && y >= 1 && x>= 1 && y <= 99){

            if (arr[x][y] != 1) {
                
                arr[x][y] = 1;
                sum += 2;
        
                if (y < 99) {
                    if (arr[x][y+1] == 1)
                        sum -= 0.5;
                }
                
                if (arr[x][y-1] == 1)
                    sum -= 0.5;
                
                if (x < 99) {
                    if (arr[x+1][y] == 1)
                        sum -= 0.5;
                
                }
                if (arr[x-1][y] == 1)
                    sum -= 0.5;
                
            }
        }   
    }

    cout << fixed << setprecision(1) << sum << endl;

    return 0;
}