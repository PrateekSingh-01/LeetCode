class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* beforeA = list1;

    for (int i = 0; i < a - 1; i++) {
        beforeA = beforeA->next;
    }


    ListNode* atB = beforeA->next;

    for (int i = a; i <= b; i++) {
        atB = atB->next;
    }


    ListNode* tail2 = list2;

    while (tail2->next) {
        tail2 = tail2->next;
    }

    
    beforeA->next = list2;
    tail2->next = atB;

    return list1;

    }
};