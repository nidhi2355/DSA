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
        if(!head) return head;

        int cnt=0;
        ListNode* temp= head;

        while(temp){
            cnt++;
            temp= temp->next;
        }

        k= k%cnt;

        if(k==0) return head;

        ListNode* fast= head;

        for(int i=0; i<k; i++) fast= fast->next;

        temp= head;
        while(fast->next){
            fast= fast->next;
            temp= temp->next;
        }

        ListNode* newhead= temp->next;
        temp->next= nullptr;

        temp= newhead;
        while(temp->next){
            temp= temp->next;
        }

        temp->next= head;

        return newhead;
    }
};