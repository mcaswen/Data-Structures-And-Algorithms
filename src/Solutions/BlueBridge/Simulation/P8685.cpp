#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map < int, unordered_map<int, int> > info;

int main()
{
    int n, m, t; cin >> n >> m >> t;
    
    for (int i = 0; i < m; i++)
    {
        int ts, id; cin >> ts >> id;
        info[id][ts]++;
    }

    int ans = 0;

    for (auto& [id, ordersByTime] : info)
    {
        int pri = 0;
        bool isPri = false;
        for (int j = 1; j <= t; j++)
        {
            int num = (ordersByTime.find(j) != ordersByTime.end()) ? ordersByTime[j] : 0;

            pri += num == 0 ? -1 : num * 2;
            if (pri < 0) pri = 0;

            if (!isPri && pri > 5) isPri = true;
            if (isPri && pri <= 3) isPri = false;
        }

        if (isPri) ans++;
    }

    cout << ans << endl;

    return 0;
}