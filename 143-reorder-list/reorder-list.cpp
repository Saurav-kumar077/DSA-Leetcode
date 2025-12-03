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
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast =head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr!=NULL){
            ListNode* nextNode = curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return;

        ListNode* firstHlf = findMiddle(head);
        ListNode* secondHalf = reverse(firstHlf->next);
        firstHlf->next = NULL;

        ListNode* p1 = head;
        ListNode* p2 =secondHalf;

        while(p2!=NULL){
            ListNode* t1 = p1->next;
            ListNode* t2 = p2->next;

            p1->next = p2;
            p2->next = t1;

            p1=t1;
            p2=t2;
            
        }
    }
};