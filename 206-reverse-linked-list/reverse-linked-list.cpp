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
    void reverse(ListNode* &head,ListNode* curr,ListNode* prev){
        if(curr==NULL){
            head=prev;
            return;
        }
        ListNode*foreword =curr->next;
        reverse(head,foreword,curr);
        curr->next=prev;



    }
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*curr=head;
        ListNode*prev= NULL;
        reverse(head,curr,prev);
        return head;
        
        
    }
};