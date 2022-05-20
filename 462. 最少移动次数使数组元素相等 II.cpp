#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;
class Solution
{
public:
    int quickSelect(vector<int> &nums, int left, int right, int index)
    {
        int q = randomPartition(nums, left, right);
        if (q == index)
        {
            return nums[q];
        }
        else
        {
            return q < index ? quickSelect(nums, q + 1, right, index) : quickSelect(nums, left, q - 1, index);
        }
    }
    int randomPartition(vector<int> &nums, int left, int right)
    {
        int i = rand() % (right - left + 1) + left;
        swap(nums[i], nums[right]);
        return partition(nums, left, right);
    }
    int partition(vector<int> &nums, int left, int right)
    {
        int i = left - 1, x = nums[right];
        for (int j = left; j < right; j++)
        {
            if (nums[j] <= x)
            {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[right]);
        return i + 1;
    }

    int minMoves2(vector<int> &nums)
    {
        srand(time(0));
        int n = nums.size(), x = quickSelect(nums, 0, n - 1, n / 2), ret = 0;
        for (int i = 0; i < n; ++i)
        {
            ret += abs(nums[i] - x);
        }
        return ret;
    }
};