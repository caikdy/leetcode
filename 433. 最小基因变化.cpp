#include <vector>
#include <iostream>
#include <queue>
using namespace std;
class Solution
{
    bool diff(string a, string b)
    {
        int sum = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
            {
                sum++;
            }
            if (sum > 1)
            {
                return false;
            }
        }
        return true;
    }

public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        vector<bool> visit(bank.size());
        queue<string> que;
        que.emplace(start);
        int depth = 0, current_num = 0;
        while (!que.empty())
        {
            if (current_num == 0)
            {
                current_num = que.size();
                depth++;
            }
            current_num--;
            string current_status = que.front();
            for (int i = 0; i < bank.size(); i++)
            {
                if (visit[i] == true)
                {
                    continue;
                }
                if (diff(current_status, bank[i]))
                {
                    que.emplace(bank[i]);
                    if (bank[i] == end)
                    {
                        return depth;
                    }
                    visit[i] = true;
                }
            }
            que.pop();
        }
        return -1;
    }
};