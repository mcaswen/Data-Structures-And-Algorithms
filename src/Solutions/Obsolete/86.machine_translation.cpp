#include <iostream>
#include <queue>
#include <set>

using namespace std;

set <int> memory;
queue <int> q;

signed main() {

    int M, N;
    cin >> M >> N;

    int times = 0;

    while (N--) {

        int word;
        cin >> word;

        auto p = memory.find(word);

        if (p == memory.end()) {

            if (q.size() < M) {
                
                q.push(word);
                memory.insert(word);
            
            } else {
                
                memory.erase(q.front());
                q.pop();

                q.push(word);
                memory.insert(word);

            }

            times++;

        }

    }

    cout << times << endl;

    return 0;
}