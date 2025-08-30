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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        
        // Step 1: find length and tail
        ListNode* tail = head;
        int n = 1;
        while (tail->next) {
            tail = tail->next;
            n++;
        }
        
        // Step 2: make it circular
        tail->next = head;
        
        // Step 3: find new head
        k = k % n;
        int stepsToNewHead = n - k;
        
        ListNode* newTail = tail;
        while (stepsToNewHead--) {
            newTail = newTail->next;
        }
        
        // Step 4: break the circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        
        return newHead;
    }
};
