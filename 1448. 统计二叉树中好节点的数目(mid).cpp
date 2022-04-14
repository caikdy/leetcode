/*
tip:
    1.通过dfs进行遍历,维持一个变量max_val,若val>=max_val,则count++

 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <algorithm>
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
    void dfs(TreeNode *root, int max_val, int &count)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->val >= max_val)
        {
            max_val = root->val;
            count++;
        }
        dfs(root->left, max_val, count);
        dfs(root->right, max_val, count);
    }
    int goodNodes(TreeNode *root)
    {
        int count = 0;
        dfs(root, root->val, count);
        return count;
    }
};