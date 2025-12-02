#include <iostream>
#include <vector>

using namespace std;

vector <int> arr(1e5 + 5, 0);

//快慢指针，找一个数组中的重复元素（只有两个元素重复）
int seek(int n) {

    int fast = 1;
    int slow = 1;

    while (fast != slow) {

        slow = arr[slow];
        fast = arr[arr[fast]];

    }

    slow = 1;

    while (fast != slow) {

        slow = arr[slow];
        fast = arr[fast];

    }

    return arr[fast];

}