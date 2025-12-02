#include <unordered_map>

using namespace std;

unordered_map <int, int> father;
unordered_map <int, int> set_size;

int find(int a) {

    if (father.count(a) == 0) {

        father[a] = a;
        set_size[a] = 1;

    }

    if (father[a] != a)
        father[a] = find(father[a]);

     return father[a];

}

bool isSameSet(int a, int b) {

    return find(a) == find(b);

}

void unionSet(int a, int b) {

    if (isSameSet(a, b)) return;

    int top_a = find(a);
    int top_b = find(b);

    if (set_size[top_a] >= set_size[top_b]) {

        father[top_b] = top_a;
        set_size[top_a] += set_size[top_b];


    } else {

        father[top_a] = top_b;
        set_size[top_b] += set_size[top_a];

    }

}

