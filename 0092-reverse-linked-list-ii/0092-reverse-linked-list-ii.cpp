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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Step 1: Move prev to the node before 'left'
        ListNode* prev = dummy;
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Step 2: Reverse the sublist
        ListNode* curr = prev->next;
        ListNode* prevNode = nullptr;

        for (int i = 0; i < right - left + 1; i++) {
            ListNode* nextNode = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = nextNode;
        }

        // Step 3: Reconnect the reversed sublist
        ListNode* tail = prev->next;  // Original left node, now the tail
        prev->next = prevNode;
        tail->next = curr;

        return dummy->next;
    }
};