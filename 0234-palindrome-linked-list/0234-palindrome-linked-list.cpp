class Solution {
public:
    bool isPalindrome(ListNode* head) {

        if (!head || !head->next)
            return true;

        int len = 0;
        ListNode* curr = head;

        while (curr) {
            len++;
            curr = curr->next;
        }

        stack<int> st;

        curr = head;

    
        for (int i = 0; i < len / 2; i++) {
            st.push(curr->val);
            curr = curr->next;
        }

    
        if (len % 2 == 1) {
            curr = curr->next;
        }

        
        while (curr) {
            if (st.top() != curr->val)
                return false;

            st.pop();
            curr = curr->next;
        }

        return true;
    }
};