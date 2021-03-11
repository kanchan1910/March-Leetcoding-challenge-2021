class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       if(headA == NULL || headB == NULL)
       {
           return NULL;
       }
        ListNode* d1 = headA;
        ListNode* d2 = headB;
        while(d1 != d2)
        {
            if(d1 == NULL)
            {
                d1 = headB;
            }
            else if(d1 != NULL)
            {
                d1 = d1 -> next;
            }
            if(d2 == NULL)
            {
                d2 = headA;
            }
            else if(d2 != NULL)
            {
                d2 = d2 -> next;
            }
        }
        return d1;
    }
};
https://youtu.be/u4FWXfgS8jw 
