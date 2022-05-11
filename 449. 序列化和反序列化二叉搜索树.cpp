/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string res;
        if (root == NULL)
        {
            return "#";
        }
        res = res.append(to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right));
        return res;
    }
    vector<string> split(const string &str, char dec)
    {
        int pos = 0;
        int start = 0;
        vector<string> res;
        while (pos < str.size())
        {
            while (pos < str.size() && str[pos] == dec)
            {
                pos++;
            }
            start = pos;
            while (pos < str.size() && str[pos] != dec)
            {
                pos++;
            }
            if (start < str.size())
            {
                res.emplace_back(str.substr(start, pos - start));
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        vector<string> vec = split(data, ',');
        int root = 0;
        return rdeserialize(vec, root);
    }
    TreeNode *rdeserialize(vector<string> &vec, int &root)
    {
        if (vec[root] == "#")
        {
            return NULL;
        }
        TreeNode *node = new TreeNode(stoi(vec[root]));
        root++;
        node->left = rdeserialize(vec, root);
        root++;
        node->right = rdeserialize(vec, root);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
int main()
{
    Codec code;
    vector<string> vec = code.split("dsad,231564,321,32,165,13,21,3", ',');
    for (auto str : vec)
    {
        cout << str << "\t";
    }
}