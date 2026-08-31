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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head or !head->next or !head->next->next) return {-1, -1};

        int first=-1, last= -1, mind= INT_MAX;

        ListNode* temp= head->next;
        ListNode* prev= head;
        int pos=1;

        while(temp->next){
            if((temp->val > temp->next->val and temp->val > prev->val) or (temp->val < prev->val and temp->val < temp->next->val)){
                if(first==-1) first= pos;
                else{
                    mind= min(mind, (pos- last));
                }
                last= pos;
            }
            prev= temp;
            temp= temp->next;
            pos++;
        }

        if(mind==INT_MAX) return {-1, -1};
        return {mind, last-first};
    }
};