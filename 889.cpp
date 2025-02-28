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
    TreeNode* func(int preSt, int postSt, int preEnd,
                    vector<int>& pre, vector<int>& post) {
        if (preSt > preEnd)
            return NULL;

        TreeNode* root = new TreeNode(pre[preSt]);
        if (preSt == preEnd)
            return root;

        int next = pre[preSt + 1]; // root of left subtree

        int j = postSt;
        while (post[j] != next)
            j++;

        int num = j - postSt + 1;
        root->left =
            func(preSt + 1, postSt, preSt + num, pre, post);
        root->right =
            func(preSt + num + 1, j + 1, preEnd, pre, post);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& pre,
                                   vector<int>& post) {
        int n = pre.size();
        return func(0, 0, n - 1, pre, post);
    }
};
