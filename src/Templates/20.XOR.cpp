#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;


//swap a, b
void swap(int& a, int& b) {

    a ^= b;
    b ^= a;
    a ^= b;

}

//swap idx i, j if i == j Wrong. Require different memory space.
int* swap(int a[], int i, int j) {

    a[i] ^= a[j];
    a[j] ^= a[i];
    a[i] ^= a[j];

    return a;

}

// return max(a, b) without comparison or judgement

int sign(int a) {

    return ((a >> 31) & 1) ^ 1;

}

int flip(int a) {

    return a ^ 1;

}

// No overflow dealing version

int judge(int a, int b) {

    int c = a - b;

    int returna = sign(c);
    int returnb = flip(returna);
    
    return a * returna + b * returnb;

}

//if a > 0 && b < 0, the result may overflow the max value, so that the sign() function doesn't work.
//Version with overflow dealing.

int judge1(int a, int b) {

    int c = a - b;

    int sa = sign(a);
    int sb = sign(b);
    int sc = sign(c);

    int diffs = sa ^ sb;
    int sames = flip(diffs);

    int returna = sames * sc + sa * diffs;
    int returnb = flip(returna);

    return a * returna + b * returnb;

}

//Find the missing num in an array.

int FindMissingNum(vector <int>& nums, vector <int>& missednums) {

    int sum = 0, missedsum = 0;
    for (int i = 0; i < missednums.size(); i++) {

        sum ^= nums[i];
        missedsum ^= missednums[i];

    }

    sum ^= nums[nums.size()];

    return sum ^ missedsum;

}

//Find the only num that exists odd times

int FindOddNum(vector <int>& nums) {

    int sum = 0;
    for (auto p: nums) sum ^= p;

    return sum;

}

//Find the only two num that exists odd times

int FindRight1(int num) {

    unsigned int unum = num;

    return unum & (-unum);

}


vector <int> FindOdd2Num(vector <int>& nums) {

    vector <int> ans;
    int sum = 0;
    
    for (auto p: nums) {
        
        sum ^= p;

    }

    int diffbit = FindRight1(sum);
    int sum2 = 0;

    for (auto p: nums) {

        if ((p & diffbit) == 0) 
            sum2 ^= p;

    }   

    ans.push_back(sum2);
    ans.push_back(sum2 ^ sum);

    return ans;
    
}

//If in an array, every single num exists m times, while a special num exists n times(n < m), find the num.

int FindSnum(vector <int> nums, int m) {

    vector <int> bits(32, 0);
    for (int i = 0; i < nums.size(); i++)
        for (int j = 0; j < 32; j++) {

            bits[j] += ((unsigned int)nums[i] >> j) & 1;

        }

    int ans = 0;

    for (int i = 0; i < 32; i++) {

        if (bits[i] % m != 0) 
            ans |= (1 << i);

    }

    return ans;

}