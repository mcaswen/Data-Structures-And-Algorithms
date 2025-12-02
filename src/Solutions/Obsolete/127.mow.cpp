#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;

struct {

    int a;
    int b;

} cust_snack[100005];


unordered_map <int, int> father;
unordered_map <int, int> set_size;
vector <int> cust(1e5+5, 0);
unordered_set <int> sets;

int find(int a) {

    if (father.count(a) == 0) {

        father[a] = a;
        set_size[a] = 1;
        sets.insert(a);

    }

    if (father[a] != a) {

        father[a] = find(father[a]);

    }

    return father[a];

} 

int union_set(int a, int b) {

    int fa = find(a);
    int fb = find(b);

    if (fa >= fb) {

        father[fb] = fa;
        set_size[fa] += set_size[fb];
        sets.erase(fb);

    } else {

        father[fa] = fb;
        set_size[fb] += set_size[fa];
        sets.erase(fa);

    }

}

signed main() {

    int ans = 0;

    int n, k;
    cin >> n >> k;

    









    return 0;
}