/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map < ListNode*, int > vis;
        for(ListNode* cur = head;cur ; cur = cur->next){
            if(vis[cur]) return 1;
            vis[cur] = 1;
        }
        return 0;
    }
};