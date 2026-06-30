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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        // 'prev' tracks the node immediately preceding the current group
        ListNode* prev = head; 
        // We start evaluating from the second group because the first group has length 1 (odd)
        int expectedGroupLen = 2; 
        
        while (prev && prev->next) {
            ListNode* curr = prev->next;
            ListNode* tail = prev->next;
            int actualLen = 0;
            
            // Step 1: Count the available elements in the current group
            while (actualLen < expectedGroupLen && tail) {
                tail = tail->next;
                actualLen++;
            }
            
            // Step 2: If the group contains an even number of elements, reverse it
            if (actualLen % 2 == 0) {
                ListNode* groupPrev = tail; // Connects tail-end of reversed group to the remaining list
                ListNode* groupCurr = curr;
                
                // Classic iterative linked list reversal for 'actualLen' nodes
                for (int i = 0; i < actualLen; ++i) {
                    ListNode* nextNode = groupCurr->next;
                    groupCurr->next = groupPrev;
                    groupPrev = groupCurr;
                    groupCurr = nextNode;
                }
                
                // Re-link the preceding node to the new head of this reversed segment
                ListNode* oldNext = prev->next;
                prev->next = groupPrev;
                prev = oldNext; // The old head becomes the new tail of the segment
            } else {
                // If odd, skip reversing and just move 'prev' forward to the end of this group
                for (int i = 0; i < actualLen; ++i) {
                    prev = prev->next;
                }
            }
            
            // Increment expected size for the next consecutive group
            expectedGroupLen++;
        }
        
        return head;
    }
};
