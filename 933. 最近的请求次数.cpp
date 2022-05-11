#include <queue>
using namespace std;
class RecentCounter
{
public:
    RecentCounter()
    {
    }

    int ping(int t)
    {
        que.emplace(t);
        while (t - que.front() > 3000)
        {
            que.pop();
        }
        return que.size();
    }

private:
    queue<int> que;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */