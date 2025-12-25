class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (!head || left == right) return head;

        ListNode* temp = head;
        ListNode* before = nullptr;
        int pos = 1;

        while (pos < left) {
            before = temp;
            temp = temp->next;
            pos++;
        }
        ListNode* curr = temp;
        ListNode* prev = nullptr;
        int times = right - left + 1;
        while (times-- && curr) {
            ListNode* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        temp->next = curr;
        if (before)
            before->next = prev;
        else
            head = prev;         

        return head;
    }
};
