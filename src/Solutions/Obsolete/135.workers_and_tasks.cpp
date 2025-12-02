#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> workers(1e5+5, 0);
vector <int> tasks(1e5+5, 0);
deque <int> dq;

bool isok(int mid, int pills, int str, int wo_num) {

    int ri = mid - 1;
    int le = 0;

    int wo_ri = wo_num - 1;
    int wo_le = wo_num - mid;

    int pills = pills;

    if (!wo_le) return false;

    for (int i = wo_le; i < wo_num; i++) {

        while (le <= ri && workers[i] >= tasks[le]) {

            dq.push_back(le++);

        } 

        if (dq.size() && workers[i] >= tasks[dq.front()]) {

            dq.pop_front();

        } 

        else {

            bool ok = false;

            while (le <= ri && pills > 0 && workers[i] + str > tasks[le]) {

                if (!ok) {

                    ok = true;
                    pills--;

                }

                dq.push_back(le++);

            }

            if (!ok && dq.empty()) return false;

            else {

                dq.pop_back();

            }

        }

    }

    return true;

}

int binary(int tas, int wor, int pills, int str) {

    sort(workers.begin(), workers.end());
    sort(tasks.begin(), tasks.end());

    int le = 0;
    int ri = min(tas, wor);
    int n = workers.size();

    while (le <= ri) {

        int mid = le + ((ri - le) >> 1);

        if (le == ri) return mid;

        if (isok(mid, pills, str, n)) {

            le = mid + 1;

        } else {

            ri = mid - 1;

        }

    }

}