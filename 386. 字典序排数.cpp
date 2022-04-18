#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> vec(n);
        int num = 1;

        for (int i = 0; i < n; i++)
        {
            vec[i] = num;
            if (num * 10 < n)
            {
                num *= 10;
            }
            else
            {
                while (num % 10 == 9 || num + 1 > n)
                {
                    num /= 10;
                }
                num++;
            }
        }
        return vec;
    }
};