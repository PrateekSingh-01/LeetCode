class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        
        int len = 0;
        ListNode* temp = head;

        while (temp) {
            len++;
            temp = temp->next;
        }

        int size = len / k;
        int rem = len % k;

        vector<ListNode*> ans;

        temp = head;

        for (int i = 0; i < k; i++) {

            
            int currSize = size;

            if (rem > 0) {
                currSize++;
                rem--;
            }

            if (currSize == 0) {
                ans.push_back(nullptr);
                continue;
            }

        
            ListNode* partHead = temp;

    
            for (int j = 1; j < currSize; j++) {
                temp = temp->next;
            }

            
            ListNode* next = temp->next;

            
            temp->next = nullptr;

            ans.push_back(partHead);

            
            temp = next;
        }

        return ans;
    }
};