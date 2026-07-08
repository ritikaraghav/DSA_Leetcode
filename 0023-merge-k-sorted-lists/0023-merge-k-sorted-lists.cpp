#include <iostream>
#include <queue>
#include <vector>



// Custom comparator to create a min-heap based on node values
struct CompareNode {
    bool operator()(const ListNode* a, const ListNode* b) {
        // Returns true if 'a' has higher value than 'b'
        // This ensures the SMALLEST value is always at the top
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        // Define the min-heap priority queue
        std::priority_queue<ListNode*, std::vector<ListNode*>, CompareNode> minHeap;
        
        // Step 1: Push the head of each non-empty linked list into the heap
        for (ListNode* head : lists) {
            if (head != nullptr) {
                minHeap.push(head);
            }
        }
        
        // Create a dummy node to easily build the result list
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Step 2: Process the nodes until the heap is empty
        while (!minHeap.empty()) {
            // Get the node with the smallest value
            ListNode* smallestNode = minHeap.top();
            minHeap.pop();
            
            // Append it to our merged list
            tail->next = smallestNode;
            tail = tail->next;
            
            // If this node has a next node, push it into the heap
            if (smallestNode->next != nullptr) {
                minHeap.push(smallestNode->next);
            }
        }
        
        return dummy.next;
    }
};
