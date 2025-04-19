class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) return head;

        // Step 1: Check if there are at least k nodes left
        ListNode* temp = head;
        int count = 0;
        while (temp != NULL && count < k) {
            temp = temp->next;
            count++;
        }

        // Step 2: If there are at least k nodes, reverse them
        if (count == k) {
            ListNode* prev = NULL;
            ListNode* curr = head;
            ListNode* next = NULL;
            int c = 0;

            while (curr != NULL && c < k) {
                next = curr->next;  // Save next node
                curr->next = prev;  // Reverse current node
                prev = curr;        // Move prev ahead
                curr = next;        // Move curr ahead
                c++;
            }

            // Step 3: Recur for the remaining list and connect
            head->next = reverseKGroup(curr, k); // not head, use curr
            return prev; // new head after reversal
        }

        // Step 4: Less than k nodes remaining, return as-is
        return head;
    }
};
