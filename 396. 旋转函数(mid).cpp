#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int len = nums.size();
        int sum = 0, add = 0;
        for (int i = 0; i < len; i++)
        {
            sum += i * nums[i];
            add += nums[i];
        }
        int max_sum = sum;
        for (int i = len - 1; i > 0; i--)
        {
            sum += add - len * nums[i];
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};