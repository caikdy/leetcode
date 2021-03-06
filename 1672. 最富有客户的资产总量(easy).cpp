#include <vector>
using namespace std;

class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int max_assets = 0;
        for (auto accout : accounts)
        {
            int assets = 0;
            for (auto asset : accout)
            {
                assets += asset;
            }
            max_assets = max(max_assets, assets);
        }
        return max_assets;
    }
};