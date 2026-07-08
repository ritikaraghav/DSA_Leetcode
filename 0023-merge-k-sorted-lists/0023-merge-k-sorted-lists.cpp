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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>> pq;

        for(int i = 0; i < lists.size(); ++i) {
            if(lists[i]) pq.push({-lists[i]->val, lists[i]});
        }

        auto head = new ListNode();
        auto cur = head;

        while(!pq.empty()) {
            cur->next = pq.top().second;
            pq.pop();
            cur = cur->next;
            if(cur->next) {
                pq.push({-cur->next->val, cur->next});
            }
        }

        head = head->next;

        return head;
    }
};