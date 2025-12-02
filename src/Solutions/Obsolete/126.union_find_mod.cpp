#include <iostream>
#include <map>
#include <unordered_map>

#define endl '\n'

using namespace std;

unordered_map <int, int> father;
unordered_map <int, int> set_size;

int find(int a) {

    if (father.count(a) == 0) {

        father[a] = a;
        set_size[a] = 1;

    }

    if (father[a] != a) {

        father[a] = find(father[a]);

    }

    return father[a];

}

int issameset(int a, int b) {

    return find(a) == find(b);

}

void union_set(int a, int b) {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int fa = find(a);
    int fb = find(b);

    if (fa != fb) {

        if (set_size[fa] > set_size[fb]) {

            father[fb] = fa;
            set_size[fa] += set_size[fb];

        } else {

            father[fa] = fb;
            set_size[fb] += set_size[fa];

        }

    }

}

signed main() {

    int N, M;
    cin >> N >> M;

    int a;

    while (M--) {

        int z, a, b;
        cin >> z >> a >> b;

        if (z == 1) {

            union_set(a, b);

        } else {

            if (issameset(a, b)) cout << "Y" << endl;
            else cout << "N" << endl;

        }

    }

    return 0;
}