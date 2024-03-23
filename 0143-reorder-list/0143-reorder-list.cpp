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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        auto lst = slow;
        while(fast){
            lst = slow;
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
        }
        ListNode* rev = rev_half(slow);
        lst->next = nullptr;
        bool ok = 1;
        auto up = head, down = rev;
        auto nxt_up = head->next, nxt_down = rev;
        while(down){
            if(ok){
                up->next = down;
                up = down;
                down = down->next;
            }else{
                up->next = nxt_up;
                up = nxt_up;
                nxt_up = nxt_up->next;
            }
            ok ^= 1;
        }
        if(nxt_up) up->next = nxt_up;
    }
    ListNode* rev_half(ListNode* cur){
        ListNode* lst = nullptr;
        while(cur){
            auto nxt = cur->next;
            cur->next = lst;
            lst = cur;
            cur = nxt;
        }
        return lst;
    }
};