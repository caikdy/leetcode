#include <vector>
#include <set>
using namespace std;
class Solution
{
public:
    void dfs(int x, int y, const int &m, const int &n, vector<vector<bool>> &visit, set<pair<int, int>> &se, const vector<vector<int>> &heights)
    {
        if (visit[x][y] == true)
        {
            return;
        }
        se.emplace(x, y);
        visit[x][y] = true;
        if (x - 1 >= 0 && heights[x][y] <= heights[x - 1][y])
        {
            dfs(x - 1, y, m, n, visit, se, heights);
        }
        if (x + 1 < m && heights[x][y] <= heights[x + 1][y])
        {
            dfs(x + 1, y, m, n, visit, se, heights);
        }
        if (y - 1 >= 0 && heights[x][y] <= heights[x][y - 1])
        {
            dfs(x, y - 1, m, n, visit, se, heights);
        }
        if (y + 1 < n && heights[x][y] <= heights[x][y + 1])
        {
            dfs(x, y + 1, m, n, visit, se, heights);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> visit_pac(m, vector(n, false)), visit_alt(m, vector(n, false));
        set<pair<int, int>> pac, alt;
        for (int i = 0; i < m; i++)
        {
            dfs(i, 0, m, n, visit_pac, pac, heights);
            dfs(i, n - 1, m, n, visit_alt, alt, heights);
        }
        for (int j = 0; j < n; j++)
        {
            dfs(0, j, m, n, visit_pac, pac, heights);
            dfs(m - 1, j, m,n, visit_alt, alt, heights);
        }
        vector<vector<int>> res;
        for (auto index : pac)
        {
            if (alt.find(index) != alt.end())
            {
                vector<int> temp;
                temp = {index.first, index.second};
                res.emplace_back(temp);
            }
        }
        return res;
    }
};









class Solution
{
public:
    void dfs(int x, int y, const int &m, const int &n, vector<vector<bool>> &visit, set<pair<int, int>> &se, const vector<vector<int>> &heights)
    {
        if (visit[x][y] == true)
        {
            return;
        }
        se.emplace(x, y);
        visit[x][y] = true;
        if (x - 1 >= 0 && heights[x][y] <= heights[x - 1][y])
        {
            dfs(x - 1, y, m, n, visit, se, heights);
        }
        if (x + 1 < n && heights[x][y] <= heights[x + 1][y])
        {
            dfs(x + 1, y, m, n, visit, se, heights);
        }
        if (y - 1 >= 0 && heights[x][y] <= heights[x][y - 1])
        {
            dfs(x, y - 1, m, n, visit, se, heights);
        }
        if (y + 1 < m && heights[x][y] <= heights[x][y + 1])
        {
            dfs(x, y + 1, m, n, visit, se, heights);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> visit_pac(m, vector(n, false)), visit_alt(m, vector(n, false));
        set<pair<int, int>> pac, alt;
        for (int i = 0; i < n; i++)
        {
            dfs(i, 0, m, n, visit_pac, pac, heights);
            dfs(i, m - 1, m, n, visit_alt, alt, heights);
        }
        for (int j = 0; j < m; j++)
        {
            dfs(0, j, m, n, visit_pac, pac, heights);
            dfs(n - 1, j, m, n, visit_alt, alt, heights);
        }
        vector<vector<int>> res;
        cout<<"alt:"<<endl;
        for(auto aa:alt){
            cout<<aa.first<<','<<aa.second<<'\t';
        }
        cout<<"\npac: "<<endl;
        for (auto index : pac)
        {
            cout<<index.first<<','<<index.second<<'\t';
            if (alt.find(index) != alt.end())
            {
                vector<int> temp;
                temp = {index.first, index.second};
                res.emplace_back(temp);
            }
        }
        return res;
    }
};