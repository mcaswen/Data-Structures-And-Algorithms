#include <iostream>
#include <vector>

using namespace std;

vector <int> visited(1e7 + 5, 0), prime(1e7 + 5, 0);


//埃氏筛
void sieve1(int n) {

    int cnt = 0;

    for (int i = 2; i * i <= n; i++) {

        if (visited[i] == 1) continue;

        for (long long j = (long long)i * i; j <= n; j += i) {

            visited[j] = 1;

        } 

    }

    for (int i = 2; i <= n; i++) {

        if (visited[i] == 0) {
            
            cnt++;
            //cout << i << endl;
        
        }
    }

}


//欧拉筛
void sieve2(int n) {
    int cnt = 0;

    for (int i = 2; i <= n; i++) {

        // 1. 如果 i 还未被标记，说明它是质数，就将其存入 prime 数组
        if (!visited[i]) {        // visited[i] == 0 表示没有被标记为合数
            prime[cnt++] = i;
        }

        // 2. 用 prime 数组中已找到的质数去“筛”i 的倍数
        for (int j = 0; j < cnt; j++) {
            // 如果 i * prime[j] 已经超过范围 n，就没必要继续了
            if (1LL * i * prime[j] > n) {
                break;
            }

            // 将 i * prime[j] 标记为合数
            visited[i * prime[j]] = 1;

            // 如果 prime[j] 能整除 i，说明 i 的最小质因子就是 prime[j]
            // 这样的情况下，就要 break，防止重复标记
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}

//改进埃氏筛,只计数
void sieve3(int n) {

    // cnt 初始为 (n+1)/2，表示 [1..n] 之间的「奇数」数量
    // 比如 n=10 => 奇数有 1,3,5,7,9，总共有 5 个
    int cnt = (n + 1) / 2;

    // 从 i=3 开始，步长为 2（只处理奇数），直到 i*i <= n
    for (int i = 3; i * i <= n; i += 2) {

        // 如果 i 还没有被标记为合数，说明 i 是奇数里的潜在质数
        if (!visited[i]) {

            // j=i*i 是奇数，2*i 是偶数，故 j 依然保持在奇数区间
            for (int j = i * i; j <= n; j += 2 * i) {

                // 如果 j 尚未被标记，就将其标记为合数并减少计数
                if (!visited[j]) {
                    cnt--;
                    visited[j] = 1;
                }
            }
        }
    }
}


