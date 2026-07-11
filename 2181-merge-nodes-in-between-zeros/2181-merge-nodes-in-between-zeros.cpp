class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        head = head->next;         

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        int currSum = 0;

        while (head) {
            if (head->val == 0) {
                tail->next = new ListNode(currSum);
                tail = tail->next;
                currSum = 0;
            } else {
                currSum += head->val;
            }
            head = head->next;
        }

        return dummy->next;
    }
};