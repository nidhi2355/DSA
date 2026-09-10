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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;

        ListNode* dummy= new ListNode(-1);
        ListNode* curr= dummy;
        ListNode* t1= l1;
        ListNode* t2= l2;

        while(t1 or t2 or carry){
            int sum= carry;

            if(t1){
                sum+= t1->val;
                t1= t1->next;
            }

            if(t2){
                sum+= t2->val;
                t2= t2->next;
            }

            carry= sum/10;
            sum%=10;

            ListNode* newnode= new ListNode(sum);
            curr->next= newnode;
            curr= curr->next;
        }

        return dummy->next;
    }
};