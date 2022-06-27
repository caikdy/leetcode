#include <vector>
using namespace std;

class Solution
{
public:
    int oddCells(int m, int n, vector<vector<int>> &indices)
    {
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        for (auto &indice : indices)
        {
            row[indice[0]]++;
            col[indice[1]]++;
        }
        int row_odd = 0, row_even = 0;
        int col_odd = 0, col_even = 0;
        for (auto num : row)
        {
            if (num % 2 == 0)
            {
                row_even++;
            }
            else
            {
                row_odd++;
            }
        }
        for (auto num : col)
        {
            if (num % 2 == 0)
            {
                col_even++;
            }
            else
            {
                col_odd++;
            }
        }
        return row_odd * col_even + row_even * col_odd;
    }
};