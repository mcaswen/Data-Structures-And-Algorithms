    #include <iostream>
    #include <vector>

    using namespace std;

    int main() {

        int m, n;

        cin >> n >> m;

        vector < vector <int> > arr(n, vector <int> (n, 0));

        for (; m; m--) {
            int x1, x2, y1, y2;
            
            cin >> x1 >> y1 >> x2 >> y2;
            
            x1--; x2--; y1--; y2--;
           
            arr[x1][y1] += 1;
            
            if (x2 + 1 < n) arr[x2 + 1][y1] -= 1;
            if (y2 + 1 < n) arr[x1][y2 + 1] -= 1;
            if (x2 + 1 < n && y2 + 1 < n) arr[x2 + 1][y2 + 1] += 1;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                
                if (i > 0) arr[i][j] += arr[i - 1][j];
                if (j > 0) arr[i][j] += arr[i][j - 1];
                if (i > 0 && j > 0) arr[i][j] -= arr[i - 1][j - 1];
            }
        }   
        
        
        for (int i = 0; i < n; i++) {

                for (int j = 0; j < n; j++) {

                    cout << arr[i][j] << " ";
    
            }
                cout << endl;

            }




        return 0;
    }