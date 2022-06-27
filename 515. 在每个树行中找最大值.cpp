#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
        {
            return res;
        }
        queue<TreeNode *> que;
        que.emplace(root);
        int n = que.size();
        int temp_max = root->val;
        while (!que.empty())
        {
            TreeNode *curr = que.front();
            que.pop();
            n--;
            if (curr->val > temp_max)
            {
                temp_max = curr->val;
            }
            if (curr->left != nullptr)
            {
                que.emplace(curr->left);
            }
            if (curr->right != nullptr)
            {
                que.emplace(curr->right);
            }
            if (n == 0)
            {
                res.emplace_back(temp_max);
                n = que.size();
                if (n != 0)
                {
                    temp_max = que.front()->val;
                }
            }
        }
        return res;
    }
};