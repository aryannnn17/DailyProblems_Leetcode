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
    int n;
    TreeNode* DFS(const string& s, int& i, int depth) {
        if (i >= n)
            return NULL;
        int j = i;
        while (j < n && s[j] == '-') 
            j++;
        int dash = j - i;
        if (depth != dash) 
            return NULL;
        
        i += dash;
        int value = 0;
        while (i < n && isdigit(s[i])) {
            value = value * 10 + (s[i] - '0');
            i++;
        }
        TreeNode* root = new TreeNode(value);
        root->left = DFS(s, i, depth + 1);
        root->right = DFS(s, i, depth + 1);
        return root;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        n = traversal.length();
        int i = 0;
        return DFS(traversal, i, 0);
    }
};
