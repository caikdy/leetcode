#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int len = nums.size();
        for (int left = 0, right = len - 1; left < right; left++)
        {
            if (nums[left] % 2 == 1)
            {
                while (left < right && nums[right] % 2 == 1)
                {
                    right--;
                }
                swap(nums[left], nums[right--]);
            }
        }
        return nums;
    }
};