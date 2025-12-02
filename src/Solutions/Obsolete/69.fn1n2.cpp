#include<iostream>
#define endl "\n"
#include<algorithm>
#include <vector>

#define ll long long
using namespace std;

vector <int> arr(1e6+5, 0);

inline ll read() {

    ll x=0,f=1;
    char ch=getchar();
    
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    
    }
    while(ch>='0' && ch<='9')
        
        x=x*10+ch-'0',ch=getchar();
    
    return x*f;
}

int main() {

    arr[1] = 1;

    for (int i = 2; i <= 1e6; i++) {
        
        arr[i] = i ^ arr[i-1];

    }

    int t;
    t = read();

    for (; t ; t--) {

        ll n1 , n2;
        n1= read();
        n2 = read();

        ll ans = arr[n1 - 1] ^ arr[n2];

        cout << ans << endl;

    }

    return 0;
}