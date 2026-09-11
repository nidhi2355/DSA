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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;

        ListNode* temp= head;
        int curr=1;

        ListNode* prev= nullptr;
        ListNode* begin= nullptr;
        ListNode* nextnode= nullptr;
        ListNode* end= nullptr;

        while(temp){
            if(curr== left-1) prev= temp;
            if(curr== left) begin= temp;
            if(curr== right) end= temp;
            if( curr== right+1){
                nextnode= temp;
                break;
            }

            temp= temp->next;
            curr++; 
        }

        if(prev) prev->next= nullptr;
        end->next= nullptr;

        reverseLL(begin);

        if(prev) prev->next= end;
        begin->next= nextnode;

        if(left==1) return end;
        return head;
    }

    void reverseLL(ListNode* head){
        ListNode* prev= nullptr;
        ListNode* temp= head;
        ListNode* nextnode;

        while(temp){
            nextnode= temp->next;
            temp->next= prev;
            prev= temp;
            temp= nextnode;
        }

    }
};