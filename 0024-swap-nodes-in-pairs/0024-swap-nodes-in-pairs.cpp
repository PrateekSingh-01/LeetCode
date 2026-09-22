class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr && curr->next) {

            ListNode* next = curr->next;

            curr->next = next->next;
            next->next = curr;

            if (prev)
                prev->next = next;
            else
                head = next;

            prev = curr;
            curr = curr->next;
        }

        return head;
    }
};