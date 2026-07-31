#include <iostream>
#include <vector>

using namespace std;

vector <int> nums(200005, 0);
vector <long long> prefix(200005, 0);

int main()
{
    int n; cin >> n;
    prefix[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
        if (i == 0) prefix[i] = nums[i];
        else prefix[i] = prefix[i-1] + nums[i];
    }

    long long ans = 0;

    for (int i = 0; i < n; ++i)
    {
        long long cursum = nums[i] * (prefix[n - 1] - prefix[i]);
        ans += cursum;
    }

    cout << ans << endl;

}