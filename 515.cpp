/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
            return res;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (q.empty() == false) {
            auto p = q.front();
            q.pop();
            auto node = p.first;
            auto level = p.second;
            if (res.size() <= level)
                res.push_back(node->val);
            else
                res[level] = max(res[level], node->val);

            if (node->left)
                q.push({node->left, level + 1});
            if (node->right)
                q.push({node->right, level + 1});
        }
        return res;
    }
};
