#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector <ll> a(200005, 0);
vector <ll> buc(1e9+5, 0);
vector <ll> maxnum(200005, 0);
vector <ll> ans(200005, 0);

struct Movie {

    ll voice;
    ll word;

};

Movie defaultMovie = {0, 0};

vector <Movie> mo(100005, defaultMovie);

int max = 0;

int main() {

    int n;
    cin >> n;
    int max = 0;


    for (int i = 1; i <= n; i++) {
        
        cin >> a[i];
        buc[a[i]]++;
        if (buc[a[i]] > max)
            max = buc[a[i]];


    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (buc[i] >= max) {
            maxnum[cnt] = i;
            cnt++;


        }
    }
    
    
    int num;
    cin >> num;

    for (int i = 1; i <= n; i++) {

        cin >> mo[i].voice;

    }

    int cnt2 = 0;
    for (int i = 1; i <= n; i++) {
         for (int j = 1; j <= n; j++) {
            if (mo[i].voice == maxnum[j]) {
                
                cnt2++; 
                ans[cnt2] = i;
                break;

            }

         }   
        
    }

    for (int i = 1; i <= n; i++) {

        cin >> mo[i].word;

    }

    if (cnt2 > 1) {
        






    }









    return 0;
}