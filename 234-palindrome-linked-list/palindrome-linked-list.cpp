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
        ListNode* slow=head;
        ListNode* fast =head;
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
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* middle =findMiddle(head);
        ListNode* secondHalf = reverse(middle);
        ListNode* p1 = head;
        ListNode* p2 = secondHalf;
        while(p2!=NULL){
            if(p1->val !=p2->val){
                return false;
            }
            p1=p1->next;
            p2=p2->next;
        }
        return true;
     
    }
};