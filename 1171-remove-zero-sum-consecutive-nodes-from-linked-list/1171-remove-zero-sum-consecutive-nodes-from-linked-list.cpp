class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> v;

        ListNode* temp = head;
        while (temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        while (true) {
            bool found = false;

            for (int i = 0; i < v.size() && !found; i++) {
                int sum = 0;

                for (int j = i; j < v.size(); j++) {
                    sum += v[j];

                    if (sum == 0) {
                        v.erase(v.begin() + i, v.begin() + j + 1);
                        found = true;
                        break;
                    }
                }
            }

            if (!found)
                break;
        }


        ListNode* dummy = new ListNode(0);
        temp = dummy;

        for (int x : v) {
            temp->next = new ListNode(x);
            temp = temp->next;
        }

        return dummy->next;
    }
};