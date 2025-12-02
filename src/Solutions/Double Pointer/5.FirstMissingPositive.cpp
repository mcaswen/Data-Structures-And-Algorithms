#include <iostream>

using namespace std;

void swp(vector <int>& arr, int a, int b) {

    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;

} 

int firstMissingPositive(vector<int>& nums) {
    
    int l = 0;
    int r = nums.size();

    while (l < r) {

        if (nums[l] == l+1) {

            l++;

        }

        else if (nums[l] > r || nums[l] <= l || nums[l] == nums[nums[l] - 1]) {

            swp(nums, l, --r);

        }
        else {

            swp(nums, l, nums[l] - 1);

        }

    }

    return l + 1;

}