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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        ListNode* temp=head;
        ListNode* prev=nullptr;
        ListNode* nextnode= nullptr;
        while(temp!=nullptr){
            ListNode* knode= findKnode(temp,k);
            if(knode==nullptr){
                if(prev!=nullptr) prev->next= temp;
                break;
            }
            nextnode= knode->next;
            knode->next= nullptr;
            knode= reverseknodes(temp);
            if(temp==head) head= knode;
            else{
                if(prev!=nullptr) prev->next= knode;
            }
            prev= temp;
            temp= nextnode;
        }
        return head;
    }
    ListNode* findKnode(ListNode* temp, int k){
        ListNode* knode=temp;
        int cnt=0;
        while(knode!=nullptr){
            cnt++;
            if(cnt==k) break;
            knode=knode->next;
        }
        return knode;
    }

    ListNode* reverseknodes(ListNode* temp){
        if(temp==nullptr or temp->next==nullptr) return temp;
        ListNode* newhead= reverseknodes(temp->next);
        ListNode* front= temp->next;
        front->next= temp;
        temp->next= nullptr;
        return newhead;
    }
};