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
    bool isPalindrome(ListNode* head) {
        auto slow = head, fast = head;
        while(fast){
            fast = fast->next;
            slow = slow->next;
            if(fast) fast = fast->next;
        }
        auto l = head, r = reverse_List(slow);
        while(r){
            if(l->val != r->val) return false;
            l =l->next;
            r =r->next;
        }
        return true;
    }
    ListNode* reverse_List(ListNode* head){
        ListNode* lst = nullptr;
        auto cur = head;
        while(cur){
            auto nxt = cur->next;
            cur->next = lst;
            lst = cur;
            cur = nxt;
        }
        return lst;
    }
};