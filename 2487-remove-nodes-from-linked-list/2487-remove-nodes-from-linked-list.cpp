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
    ListNode* removeNodes(ListNode* head) {
        stack < ListNode* > st;
        for(auto cur = head; cur ; cur = cur->next){
            st.push(cur);
        }
        int max = st.top()->val;
        ListNode* ans = st.top();
        st.pop();
        while(st.size()){
            auto cur = st.top();
            st.pop();
            if(cur->val >= max){
                max = cur->val;
                ListNode* node =new ListNode(max);
                node->next = ans;
                ans = node;
            }
        }
        return ans ;
    }
};