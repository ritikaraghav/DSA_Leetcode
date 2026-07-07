class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        unordered_map<int, ListNode*> mp;

        int prefix = 0;

        // First pass
        for (ListNode* cur = dummy; cur; cur = cur->next) {
            prefix += cur->val;
            mp[prefix] = cur;
        }

        // Second pass
        prefix = 0;
        for (ListNode* cur = dummy; cur; cur = cur->next) {
            prefix += cur->val;
            cur->next = mp[prefix]->next;
        }

        return dummy->next;
    }
};