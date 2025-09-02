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
        ListNode*slow = head;
        ListNode*fast = head;
        while(fast !=NULL && fast->next !=NULL && fast->next->next !=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverserList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* current =head;
        ListNode* next_node = nullptr;

        while(current !=NULL){
            next_node=current->next;
            current->next=prev;
            
            prev = current;
            current = next_node;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return true;
        }

        ListNode* firstHalfEnd = findMiddle(head);
        ListNode* secondHalfStart = reverserList(firstHalfEnd->next);

        ListNode* p1 =head;
        ListNode* p2 = secondHalfStart;

        bool result = true;
        while(result && p2 !=nullptr){
            if(p1->val != p2->val){
                return false;
            }
            p1=p1->next;
            p2=p2->next;
        }
        return true;
    }
};