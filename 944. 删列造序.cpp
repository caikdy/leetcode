#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int row = strs[0].length(), col = strs.size();
        int count = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                if (strs[j][i] < strs[j - 1][i])
                {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};