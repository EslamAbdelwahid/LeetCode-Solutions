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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* tail_list2 = nullptr;
        for(auto cur = list2;cur;cur=cur->next) tail_list2 = cur;
        int i  = 0;
        auto start = list1;
        while(i != a-1){
            start = start->next,++i;
        }
        auto end = list1;
        i = 0;
        while(i <= b){
            end = end->next,++i;
        }
        tail_list2->next = end;
        start->next = list2;
        return list1;
    }
};