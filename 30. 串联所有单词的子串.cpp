#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> res;
        int m = words[0].length();
        int n = words.size();
        int len = s.size();
        for (int i = 0; i < m && i + m * n <= len; i++)
        {
            unordered_map<string, int> differ;
            for (int j = 0; j < n; ++j)
            {
                ++differ[s.substr(i + j * m, m)];
            }
            for (auto &word : words)
            {
                if (--differ[word] == 0)
                {
                    differ.erase(word);
                }
            }
            for (int start = i; start < len - m * n + 1; start += m)
            {
                if (start != i)
                {
                    string word = s.substr(start + (n - 1) * m, m);
                    if (++differ[word] == 0)
                    {
                        differ.erase(word);
                    }
                    word = s.substr(start - m, m);
                    if (--differ[word] == 0)
                    {
                        differ.erase(word);
                    }
                }
                if (differ.empty())
                {
                    res.emplace_back(start);
                }
            }
        }
        return res;
    }
};