#include <iostream>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    string toGoatLatin(string sentence)
    {
        int count = 1;
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        string res;
        int len = sentence.length();
        for (int i = 0, j = 0; j < len; j++)
        {
            while (j != len && sentence[j] != ' ')
            {
                j++;
            }
            count++;
            if (count != 2)
            {
                res += ' ';
            }
            if (vowels.count(sentence[i]))
            {
                res += sentence.substr(i, j - i) + 'm' + string(count, 'a');
            }
            else
            {
                res += sentence.substr(i + 1, j - i - 1) + sentence[i] + 'm' + string(count, 'a');
            }
            i = j + 1;
        }
        return res;
    }
};