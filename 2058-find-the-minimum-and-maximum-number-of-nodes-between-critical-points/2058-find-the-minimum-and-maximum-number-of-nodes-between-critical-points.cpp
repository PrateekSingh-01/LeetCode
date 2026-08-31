class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int> idx;   
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;
        
        int i = 1; 
        
        while (next != NULL) {
            
        
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                
                idx.push_back(i);
            }
            
    
            prev = curr;
            curr = next;
            next = next->next;
            i++;
        }
        
        
        if (idx.size() < 2)
            return {-1, -1};
        
        int minDistance = INT_MAX;
        
    
        for (int i = 1; i < idx.size(); i++) {
            minDistance = min(minDistance, idx[i] - idx[i - 1]);
        }
        
    
        int maxDistance = idx.back() - idx.front();
        
        return {minDistance, maxDistance};
    }
};