#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool cmp(pair<string, int> &a, pair<string, int> &b)
{
    if (a.first.length() == b.first.length())
    {
        return a.second < b.second;
    }
    return a.first.length() > b.first.length();
}
class Solution
{
public:
    bool contain(string substr, string pristr)
    {
        int i = 0, j = 0;
        for (; i < substr.length() && j < pristr.length(); j++)
        {
            if (substr[i] == pristr[j])
                i++;
        }
        if (i == substr.length())
        {
            return true;
        }
        return false;
    }
    int findLUSlength(vector<string> &strs)
    {
        unordered_map<string, int> ma;
        for (auto str : strs)
        {
            ma[str]++;
        }
        vector<pair<string, int>> statistics;
        for (auto it : ma)
        {
            pair<string, int> temp;
            temp.first = it.first;
            temp.second = it.second;
            statistics.emplace_back(temp);
        }
        sort(statistics.begin(), statistics.end(), cmp);
        for (int i = 0; i < statistics.size(); i++)
        {
            if (statistics[i].second == 1)
            {
                int len = statistics[i].first.length();
                for (int j = 0; j < i; j++)
                {
                    if (contain(statistics[i].first, statistics[j].first))
                    {
                        len = -1;
                        break;
                    }
                }
                if (len != -1)
                {
                    return len;
                }
            }
        }
        return -1;
    }
};