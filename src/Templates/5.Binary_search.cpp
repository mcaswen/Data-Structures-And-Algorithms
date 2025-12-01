#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> arr(1000, 0);

int binarySearch1(int value, int n) { //非递归写法

    int le = 1;
    int ri = n;

    while (le < ri) {

    int mid = (le + ri) / 2;

    if (arr[mid] == value) 
        return value;
    else if (value > arr[mid]) 
        le = mid + 1;
    else 
        ri = mid - 1;

    }

    return -1;

}

int binarySearch2(int value, int le, int ri) { //递归写法

    if (le == ri)
        return -1;

    int mid = (le + ri) / 2;

    if (value == arr[mid])
        return value;

    else if (value > arr[mid])
        return binarySearch2(value, mid + 1, ri);
    
    else 
        return binarySearch2(value, le, mid - 1);
        
}


int main() {

    int cnt = 0;
    for (int i = -1; i <= 100; i += 2) {
        cnt++;
        arr[cnt] = i;

    }   
    int value = 67;

    int p = lower_bound(&arr[1], &arr[1+cnt], value) - &arr[0];//大于等于中最小的元素
    p = upper_bound(&arr[1], &arr[1+cnt], value) - &arr[0];//大于中最小的元素
    //cout << p << endl;
    
    if (arr[p] != value)
        cout << value << " Not found" << endl;
    
    else 
        cout << value << " found at " << p << "th." << endl;

    return 0;
}

//找到第一个大与等于目标数的数
int ans = -1;
int mybinary1(int le, int ri, int num) {

    int curmid = (le + ri) / 2;

    if (le > ri)
        return curmid;

    if (arr[curmid] >= num) {

        ans = arr[curmid];
        mybinary1(curmid + 1, ri, num);

    } else {

        mybinary1(le, curmid - 1, num);

    }

    return 0;

}

//在无序数组中寻找一个峰值

int n;
int mybinary2() {

    int le = 1,
        ri = n - 2;

    if (arr[0] > arr[1]) return arr[0];
    if (arr[n-1] > arr[n-2]) return arr[n-1];

    while (le < ri) {

        int mid = le + ((ri - le) >> 1);

        if (arr[mid] < arr[mid+1]) {

            le = mid + 1;

        } else {

            ri = mid;
            
        }

    }

    return arr[le];

}