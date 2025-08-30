var getIntersectionNode = function(headA, headB) {
    if (!headA || !headB) return null;

    let a = headA, b = headB;

    while (a !== b) {
        a = a ? a.next : headB;
        b = b ? b.next : headA;
    }

    return a;
};


//also a c++ solution 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t1=headA;
        ListNode *t2=headB;
        while(t1 != t2){
            t1=t1->next;
            t2=t2->next;

            if(t1 == t2) return t1;

            if(t1 == NULL) t1=headB;
            if(t2 == NULL) t2=headA;
        }
        return t1;
    }
};
