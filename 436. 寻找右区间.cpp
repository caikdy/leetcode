#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<pair<int, int>> sortbegin, sortend;
        for (int i = 0; i < intervals.size(); i++)
        {
            sortbegin.emplace_back(intervals[i][0], i);
            sortend.emplace_back(intervals[i][1], i);
        }
        sort(sortbegin.begin(), sortbegin.end());
        sort(sortend.begin(), sortend.end());
        vector<int> res(n, -1);
        for (int i = 0, j = 0; i < n; i++)
        {
            while (j < n && sortend[i].first > sortbegin[j].first)
            {
                j++;
            }
            if (j < n)
            {
                res[sortend[i].second] = sortbegin[j].second;
            }
        }
        return res;
    }
};