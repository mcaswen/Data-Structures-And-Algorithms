#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map <int, int> father;
unordered_map <int, int> tag;

int arr[50005];

int find(int a) {

    if (father.count(a) == 0) {

        father[a] = a;
        tag[a] = 0;

    }

    if (father[a] != a) {

        father[a] = find(father[a]);

    }

    return father[a];

}

int check(int a, int b) {

    int taga = tag[find(a)];
    int tagb = tag[find(b)];

    if (taga == 0 && tagb != 0) {

        return 0;

    }

    if (tagb == 0 && taga != 0) {

        return 4;

    }

    if (taga == 0 && tagb == 0) {

        return 5;

    }

    if (taga == 1) {

        if (tagb == 1) return 1;
        else if (tagb == 2) return 2;
        else return 3;

    } else if (taga == 2) {

        if (tagb == 1) return 3;
        else if (tagb == 2) return 1;
        else return 2;

    } else {

        if (tagb == 1) return 2;
        else if (tagb == 2) return 3;
        else return 1;

    }

}

void set_union(int a, int b) {

    int fa = find(a);   
    int fb = find(b);

    if (tag[fa] == 0 && tag[fb] == 0) {

        tag[fa] = 1;

    }

    father[fb] = fa;

}

void eat(int a, int b) {

    int taga = tag[find(a)];
    int fb = find(b);
    int tagb = tag[find(b)];
    int fa = find(a);


    if (taga != 0 && tagb == 0) {
        
        if (taga == 1) tag[fb] = 2;
        else if (taga == 2) tag[fb] = 3;
        else tag[fb] = 1;
    
    } else if (taga == 0 && tagb != 0){

        if (tagb == 1) tag[fa] = 3;
        else if (tagb == 2) tag[fa] = 1;
        else tag[fa] = 2;

    } else {

        tag[fa] = 1;
        tag[fb] = 2;

    }

}

signed main() {

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {

        find(i);

    }

    int ans = 0;

    while (K--) {

        int z, a, b;
        cin >> z >> a >> b;

        if (a > N || b > N || a == b) {

            ans++;
            continue;

        }

        int res = check(a, b);

        if (z == 1) {

            if (res == 1 || res == 4 || res == 5) set_union(a, b);
            else if (res == 0) set_union(b, a);
            else ans++;

        } else {

            if (res == 1 || res == 3) ans++;
            else if (res == 0 || res == 4 || res == 5) eat(a, b);

        }

    }

    cout << ans << endl;

    return 0;
}