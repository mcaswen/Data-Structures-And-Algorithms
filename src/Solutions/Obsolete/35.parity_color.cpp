    #include<iostream>
    #include<vector>

    using namespace std;

    vector <int> arr(60, 0);
    vector <string> ans(2000, " ");

    int main() {

        int t;
        cin >> t;

        for (int j = 0; j < t; j++) {
            
            int num;
            cin >> num;
            int a = 0;
            int b = 0;
            int answer = 0;


            for (int i = 0;i < num; i++) {
                
                cin >> arr[i];
                
                if (arr[i] % 2 == 0) a++;
                else b++;       
            
            }


            if (b % 2 == 0) answer = 1;

            if (answer) ans[j] = "YES";
            
            else ans[j] = "NO";
        
        }
        for (int k = 0; k < t; k++) {

            cout << ans[k] << endl;

        }

        return 0;
    }
