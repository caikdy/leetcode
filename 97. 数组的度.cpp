#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        unordered_map<int, vector<int>> counts;
        for (int i = 0; i < nums.size(); i++)
        {
            if (counts.count(nums[i]))
            {
                ++counts[nums[i]][0];
                counts[nums[i]][2] = i;
            }
            else
            {
                counts[nums[i]] = {1, i, i};
            }
        }
        int max_fre = 0;
        int min_len = 0;
        for (auto &count : counts)
        {
            if (count.second[0] > max_fre)
            {
                max_fre = count.second[0];
                min_len = count.second[2] - count.second[1] + 1;
            }
            else if (count.second[0] == max_fre && min_len > count.second[2] - count.second[1] + 1)
            {
                min_len = count.second[2] - count.second[1] + 1;
            }
        }
        return min_len;
    }
};