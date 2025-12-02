#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack <char> ans;
string str;

void print() {

    while (ans.size()) {

        cout << ans.top();
        ans.pop();

    }

}


int main() {

    int Time;
    cin >> Time;

    cin.ignore();

    while (Time--) {

        ans = stack <char> ();

        getline(cin, str);

        for (int i = 0; i < str.size(); i++) {
            
            int j = i;

            while (str[j] != ' ' && j < str.size()) {
                
                ans.push(str[j]);
                j++;
            
            }

            print();
            
            if (str[j] == ' ') {

                cout << ' ';

            }

            i = j;

        }

        cout << endl;

    }

}