#include <vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
    int getMaximumConsecutive(vector<int> &coins)
    {
        sort(coins.begin(), coins.end());
        int res = 0;
        for (auto coin : coins)
        {
            if (coin > res + 1)
            {
                break;
            }
            res += coin;
        }
        return res+1;
    }
};