class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||k==1){
            return head;
        }
        ListNode* temp =head;
        int count =0;
        while(temp!=NULL && count < k){
            temp=temp->next;
            count ++;
        }
        if(count == k){
            ListNode* next=NULL;
            ListNode* curr = head;
            ListNode* prev = NULL;
            int c = 0;

            while(curr!=NULL && c<k){
                next=curr->next;
                curr->next= prev;
                prev=curr;
                curr=next;
                c++;
            }
            if(next!=NULL){
                head->next=reverseKGroup(next,k);
            }
            return prev;

        }
        return head;
    }
      
};
