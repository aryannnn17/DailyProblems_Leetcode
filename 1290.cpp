/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        for (int i = 0; i < nums.size(); ++i)
            ans += nums[i] * pow(2, nums.size() - i - 1);
        return ans;
    }
};
