#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        int n = s.length();
        vector<int> res(n);
        for (int i = 0, idx = -n; i < n; i++)
        {
            if (s[i] == c)
            {
                idx = i;
            }
            res[i] = i - idx;
        }
        for (int i = n - 1, idx = 2 * n; i >= 0; i--)
        {
            if (s[i] == c)
            {
                idx = i;
            }
            res[i] = min(res[i], idx - i);
        }
        return res;
    }
};