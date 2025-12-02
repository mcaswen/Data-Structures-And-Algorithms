
typedef long long ll;
const int MOD = 10000007;

ll fast_pow(ll a, ll b) {

    ll res = 1;
    a %= MOD;

    while (b) {

        if (b & 1) {

            res *= a;
            res %= MOD;

        }

        a *= a;
        a %= MOD;
        b >>= 1;

    }

    return res;

}

ll gcd(ll a, ll b) {

    return b ? gcd(b, a % b) : a;

}

int x, y;

int exgcd(int a, int b, int &x, int &y) {

    if (b == 0) {

        x = 1;
        y = 0;
        return a;

    } 

    int gcd = exgcd(b, a % b, y, x);
    y -= (a / b) * x;

    return gcd;

}

//利用扩展欧几里得算法求a在模p意义下的逆元（a， p互质）
int get_inv(int a, int p) {

    int x = 1, y = 0;

    exgcd(a, p, x, y);

    return ((x % p + p) % p); // 防负数

}

//利用费马小定理求a在模p意义下的逆元（p为质数）
int get_inv_2(int a, int p) {

    int a_inv = fast_pow(a, p-2);

    return a_inv;

}

//线性求逆元
#define MAXN 1000007
int inv[MAXN];

void linear_get_inv(int p, int n) {

    inv[1] = 1;

    for (int i = 2; i <= n; i++) {

        int k = p / i;
        int r = p % i;

        inv[i] = -k * inv[r];

        inv[i] = (inv[i] % p + p) % p;

    } 

}