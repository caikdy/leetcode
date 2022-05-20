#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        vector<int> value(26);
        for (int i = 0; i < order.size(); i++)
        {
            value[order[i] - 'a'] = i;
        }
        for (int i = 1; i < words.size(); i++)
        {
            int flag = false;
            for (int j = 0; j < words[i].size() && j < words[i - 1].size(); j++)
            {
                if (value[words[i][j] - 'a'] > value[words[i - 1][j] - 'a'])
                {
                    flag = true;
                    break;
                }

                if (value[words[i][j] - 'a'] < value[words[i - 1][j] - 'a'])
                {
                    return false;
                }
            }
            if (!flag && words.size() > words.size())
            {
                return false;
            }
        }
    }
};