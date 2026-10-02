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
    ListNode* sortList(ListNode* head) {
        if(head==nullptr or head->next== nullptr) return head;
        ListNode* mid= findMid(head);
        ListNode* right= mid->next;
        mid->next= nullptr;
        ListNode* left= head;
        left= sortList(left);
        right=sortList(right);
        return mergeLL(left,right);
    }

    ListNode* findMid(ListNode* head){
        if(head==nullptr or head->next==nullptr) return head;
        ListNode* slow= head;
        ListNode* fast= head->next;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* mergeLL(ListNode* l1, ListNode* l2){
     ListNode* dummynode= new ListNode(-1);
        ListNode* temp= dummynode;
        while(l1 and l2){
            if(l1->val<=l2->val){
                temp->next=l1;
                l1=l1->next;
            }
            else{
                temp->next=l2;
                l2=l2->next;
            }
            temp= temp ->next;
        }
        if(l1) temp->next=l1;
        else temp->next=l2;
        return dummynode->next;
    }
    
    
};