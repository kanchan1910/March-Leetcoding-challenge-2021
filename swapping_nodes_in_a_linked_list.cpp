class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) 
    {
        int len = 0;
        // length of the linked list
       
        ListNode* cur = head;
        while(cur != NULL)
        {
            len++;
            cur = cur -> next;
        }
        cur = head;
         // finding kth node
        int count = 0;
        ListNode* kth = head; // let it be the kth node
        while(cur != NULL && count < k - 1)
        {
            count++;
            cur = cur -> next;
            kth = kth -> next;
        }
        cur = head;
        ListNode*  len_minus_kth = head; // let it be the kth node form the end;
        int k_from_last = len - k + 1;
        count = 0;
        while(count < k_from_last - 1 && cur != NULL)
        {
            count++;
            cur = cur -> next;
            len_minus_kth = len_minus_kth -> next;
        }
        swap(kth -> val , len_minus_kth -> val);
        return head;
    }
};
// tc o( n) + o(n) +o(n) ~ o(n)
// sc o(1)



class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) 
    {
      ListNode* a = head;
        
        ListNode* b = head;
        int count = 0;
        ListNode* kth = head;
        // let it be the kth node
        while(a != NULL)
        {
            if(count < k - 1)
            {
                   count++;
            }
            else if(count == k - 1)
            {
                kth = a;
                count++;
            }
            else if(count > k - 1)
            {
                b = b -> next;
            }
			  a = a -> next;
        }
        swap(b->val, kth->val);
        return head;
    }
};
// tc o(n)
// sc o(1)
