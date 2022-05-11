#include <vector>
using namespace std;
class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int mul = 1;
        int num = 0;
        int left = 0, right = 0;
        for (; right < nums.size(); right++)
        {
            mul *= nums[right];
            while (left <= right && mul >= k)
            {
                num += right - left;
                mul /= nums[left];
                left++;
            }
        }
        while (left <= right)
        {
            num += right - left;
            left++;
        }
        return num;
    }
};