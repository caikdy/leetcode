#include <vector>
using namespace std;

// Definition for Employee.
class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};
/*
内存消耗大，速度快
class Solution
{
public:
    int getImportance(vector<Employee *> employees, int id)
    {
        int sum = 0;
        Employee *employ;
        for (auto employee : employees)
        {
            if (employee->id == id)
            {
                employ = employee;
                break;
            }
        }
        sum += employ->importance;
        for (auto employee : employ->subordinates)
        {
            sum += getImportance(employees, employee);
        }
        return sum;
    }
};
*/
//内存消耗小，速度慢


class Solution
{
public:
    int dfs(vector<Employee *> &employees, int id)
    {
        int sum = 0;
        Employee *employ;
        for (auto employee : employees)
        {
            if (employee->id == id)
            {
                employ = employee;
                break;
            }
        }
        sum += employ->importance;
        for (auto employee : employ->subordinates)
        {
            sum += dfs(employees, employee);
        }
        return sum;
    }
    int getImportance(vector<Employee *> employees, int id)
    {
        return dfs(employees, id);
    }
};