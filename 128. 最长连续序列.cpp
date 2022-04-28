#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> nums_set;
        for (auto num : nums)
        {
            nums_set.emplace(num);
        }
        int max_len = 0;
        for (auto num : nums_set)
        {
            if (!nums_set.count(num - 1))
            {
                int current_num = num;
                int current_len = 1;
                while (nums_set.count(++current_num))
                {
                    current_len++;
                }
                max_len = max(max_len, current_len);
            }
        }
        return max_len;
    }
};
