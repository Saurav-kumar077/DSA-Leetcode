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
    ListNode* getMiddle(ListNode*head){
        if(head==nullptr){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast =head->next;

        while(fast !=nullptr && fast->next !=nullptr){
            slow = slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* list1 , ListNode* list2){
        ListNode dummy(0);
        ListNode* current = &dummy;

        while(list1 !=nullptr && list2 !=nullptr){
            if(list1->val < list2->val){
                current->next = list1;
                list1 = list1->next;
            }
            else{
                current->next=list2;
                list2=list2->next;
            }
            current = current->next;
        }

        if(list1 !=nullptr){
            current->next = list1;
        }
        else{
            current->next=list2;
        }
        return dummy.next;
    }
    ListNode* sortList(ListNode* head) {
        if(head ==nullptr || head->next==nullptr){
            return head;
        }
        //splitting the array in two parts 
        ListNode* middle = getMiddle(head);
        ListNode* rightHalf = middle->next ; 
        middle->next= nullptr;
        ListNode* leftHalf=head;

        ListNode* sortedLeft= sortList(leftHalf);
        ListNode* sortedRight= sortList(rightHalf);

        return merge(sortedLeft,sortedRight);
        
    }
};