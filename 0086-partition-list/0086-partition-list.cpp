class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* smallhead = new ListNode(0);
        ListNode* largehead = new ListNode(0);

        ListNode* smalltail = smallhead;
        ListNode* largetail = largehead;

        ListNode* curr = head;

        while (curr != nullptr) {

            if (curr->val < x) {
                smalltail->next = curr;
                smalltail = smalltail->next;
            }
            else {
                largetail->next = curr;
                largetail = largetail->next;
            }

            curr = curr->next;
        }

        smalltail->next = largehead->next;
        largetail->next = nullptr;

        return smallhead->next;
    }
};