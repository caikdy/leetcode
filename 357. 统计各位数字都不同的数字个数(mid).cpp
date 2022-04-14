class Solution
{
public:
    int permutations(int m, int n = 9)
    {
        int res = 1;
        for (int i = 0; i < m; i++, n--)
        {
            res *= n;
        }
        return res;
    }
    int countNumbersWithUniqueDigits(int n)
    {
        if (n == 0)
        {
            return 1;
        }
        vector<int> res(9);
        res[0] = 10;
        for (int i = 1; i < 9; i++)
        {

            res[i] = res[i - 1] + 9 * permutations(i);
        }
        return res[n - 1];
    }
};