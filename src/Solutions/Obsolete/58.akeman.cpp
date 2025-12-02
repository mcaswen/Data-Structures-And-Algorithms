#include <cstdio>
#include <cstring>

typedef long long ll;

ll arr[25][25][25];

ll w(ll a, ll b, ll c) {

    if (a <= 0 || b <= 0 || c <= 0)
        return 1;

    if ( a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);


    if (a < b && b < c) {
        if (arr[a][b][c-1] == 0)
            arr[a][b][c-1] = w(a, b, c-1);
        
        if (arr[a][b-1][c-1] == 0)
            arr[a][b-1][c-1] = w(a, b-1, c-1);

        if (arr[a][b-1][c] == 0)
            arr[a][b-1][c] = w(a, b-1, c);

        return arr[a][b][c-1] + arr[a][b-1][c-1] - arr[a][b-1][c];

    }

    else {

        if (arr[a-1][b][c] == 0)
            arr[a-1][b][c] = w(a-1, b, c);
        
        if (arr[a-1][b-1][c] == 0)
            arr[a-1][b-1][c] = w(a-1, b-1, c);

        if (arr[a-1][b][c-1] == 0)
            arr[a-1][b][c-1] = w(a-1, b, c-1);

        if (arr[a-1][b-1][c-1] == 0)
            arr[a-1][b-1][c-1] = w(a-1, b-1, c-1);

        
        return arr[a-1][b][c] + arr[a-1][b-1][c] + arr[a-1][b][c-1] - arr[a-1][b-1][c-1];


    }

}

int main() {

    ll a, b, c;

    memset(arr, 0, sizeof(arr));

    while (1) {
        
        scanf("%lld %lld %lld", &a, &b, &c);

        if (a == -1 && b == -1 && c == -1)
            break;

        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(a, b, c));

    }

    return 0;
}