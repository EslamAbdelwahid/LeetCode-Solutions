/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *front = new ListNode(0, head);
        ListNode *start = front;
        while(start){
            int sum = 0;
            auto end = start->next;
            while(end){
                sum += end->val;
                if(sum == 0){
                    start->next = end->next;
                   // start = end->next;
                }
                end=end->next;
            }
            if(start)
            start=start->next;
        }
        return front->next;
    }
};