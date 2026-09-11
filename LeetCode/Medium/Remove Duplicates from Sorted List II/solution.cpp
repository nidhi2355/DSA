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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;

        ListNode* temp= head;

        ListNode* dummy= new ListNode(-101);
        ListNode* curr= dummy;

        while(temp){
            ListNode* t= temp->next;

            while(t and t->val==temp->val) t= t->next;

            if(t== temp->next){
                curr->next= temp;
                curr= curr->next;
            }

            temp= t;
        }

        curr->next= nullptr;

        return dummy->next;
    }
};