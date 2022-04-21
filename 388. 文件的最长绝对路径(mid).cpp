#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int lengthLongestPath(string input)
    {
        stack<string> sta;
        int len = 0, max_len = 0;
        int deep = 0;
        string str;
        for (int i = 0, j = 0; j < input.length(); j++)
        {
            while (j < input.length() && input[j] != '\n')
            {
                j++;
            }
            str = input.substr(i, j - i);
            if (str.find('.') != -1)
            {
                max_len = len + str.length() > max_len ? len + str.length() : max_len;
            }
            sta.push(str);
            len += str.length() + 1;
            j = j + 1;
            if (j >= input.length())
            {
                break;
            }
            int count = 0;

            while (input[j] == '\t')
            {
                count++;
                j = j + 1;
            }
            while (deep >= count)
            {
                string temp = sta.top();
                len -= temp.length() + 1;
                sta.pop();
                deep--;
            }
            if (deep < count)
            {
                deep = count;
            }
            i = j;
        }
        return max_len;
    }
};
int main()
{
    string str = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    Solution aa;
    cout << aa.lengthLongestPath(str) << endl;
    return 0;
}