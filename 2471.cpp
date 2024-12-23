class Solution {
    int MinSwaps(vector<int>& val) {
        int count = 0;
        map<int, int> sorted_map;
        int n = val.size();
        for (int j = 0; j < n; ++j)
            sorted_map[val[j]] = j;
        sort(val.begin(), val.end());
        vector<bool> visited(n, false);
        int i = 0;
        for (auto& [value, idx] : sorted_map) {
            if (visited[idx]) {
                i++;
                continue;
            }
            visited[idx] = true;
            int len = 1;
            while (idx != i) {
                idx = sorted_map[val[idx]];
                visited[idx] = true;
                len++;
            }
            count += len - 1;
            i++;
        }
        return count;
    }

public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> val;
            for (int i = 0; i < size; ++i) {
                TreeNode* curr = q.front();
                q.pop();

                val.push_back(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            count += MinSwaps(val);
        }
        return count;
    }
};
