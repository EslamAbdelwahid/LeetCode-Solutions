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
    ListNode* middleNode(ListNode* head) {
        int cntNodes = 0;
        for(auto cur = head; cur ; cur = cur->next){
            ++cntNodes;
        }
        int start = (cntNodes + 1) / 2 + (cntNodes % 2 == 0);
        int i = 1;
        for(auto cur = head; cur ; cur = cur->next,++i){
            if(i >= start) return cur;
        }
        return {};
    }
};