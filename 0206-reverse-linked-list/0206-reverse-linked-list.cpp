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
    ListNode* reverseList(ListNode* head) {
        vector<int> arr;
        for(auto cur = head;cur;cur=cur->next)arr.push_back(cur->val);
        delete head;
        head = nullptr;
        ListNode *tail = nullptr;
        for(int i = arr.size() - 1;i >= 0;--i){
            ListNode *node = new ListNode(arr[i]);
            if(!head) head = tail = node;
            else{
                tail->next = node;
                tail = tail->next;
            }
        }
        return head;
    }
};