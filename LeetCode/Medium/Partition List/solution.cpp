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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;

        ListNode* lesshead= new ListNode();
        ListNode* greaterhead= new ListNode();

        ListNode* l= lesshead;
        ListNode* g= greaterhead;

        ListNode* temp= head;

        while(temp){
            if(temp->val < x){
                l->next= temp;
                l= l->next;
            }
            else{
                g->next= temp;
                g= g->next;
            }

            temp= temp->next;
        }

        l->next= greaterhead->next;
        g->next= nullptr;

        return lesshead->next;
    }
};