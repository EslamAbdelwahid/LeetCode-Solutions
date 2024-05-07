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
    ListNode* doubleIt(ListNode* head) {
        int carry = 0;
        ListNode* rev = reverse_list(head);
        ListNode* ans = nullptr ;
        for(auto cur = rev; cur ; cur = cur->next){
            int num = cur->val * 2;
            int digit = num % 10 + carry ;
            ListNode* node = new ListNode(digit);
            if(!ans) ans = node;
            else{
                node->next = ans;
                ans = node ;
            }
            if(num < 9) carry = 0;
            else carry = 1;
        }
        if(carry){
            ListNode* node = new ListNode(1);
            node->next = ans;
            ans = node ;
        }
        return ans ;
    }
    ListNode* reverse_list(ListNode* head){
        ListNode* rev = nullptr ;
        for(auto cur = head; cur; cur = cur->next){
            ListNode* node = new ListNode(cur->val);
            if(!rev){
                rev = node ;
            }else{
                node->next = rev;
                rev = node ;
            }
        }
        return rev ;
    }
};