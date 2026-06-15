/*
problem link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/?envType=daily-question&envId=2026-06-15
2095. Delete the Middle Node of a Linked List

You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.
For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
*/

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr or head->next==nullptr) return nullptr;
        ListNode* i=head;
        ListNode* j=head;
        j=j->next->next;
        while(j and j->next){
            i=i->next;
            j=j->next->next;
        }
        ListNode* delnode= i->next;
        i->next= i->next->next;
        delete(delnode);
        return head;
    }
};
