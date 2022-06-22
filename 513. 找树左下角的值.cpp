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
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> que;
        que.emplace(root);
        int curr_size = que.size();
        int curr_val = root->val;
        while (!que.empty())
        {
            TreeNode *curr_node = que.front();
            que.pop();
            if (curr_node->right != NULL)
            {
                que.emplace(curr_node->right);
            }
            if (curr_node->left != NULL)
            {
                que.emplace(curr_node->left);
            }
            curr_val = curr_node->val;
        }
        return curr_val;
    }
};