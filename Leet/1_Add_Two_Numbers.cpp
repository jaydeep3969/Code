// https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode *res;
        ListNode *head;
        int carry = 0;
        
        
        while(l1 != NULL){
            ListNode tmp = ListNode((l1->val + l2->val + carry)%10);
            carry = (l1->val + l2->val + carry)/10;
            
            if(head == NULL){
                head = &tmp;
                // res = &tmp;
            }
            else{
                head -> next = &tmp;
                head = head -> next;
            }
            
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        
        return head;
    }
};
};