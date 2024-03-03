/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int NumberOfNodes = 0;
        for(ListNode cur = head; cur != null; cur=cur.next){
            NumberOfNodes++;
        }
        int i = 0;
        ListNode Last = null;
        for(ListNode cur = head; cur != null;cur = cur.next){
            if(NumberOfNodes - i == n){
                if(Last != null) Last.next = cur.next;
                else head = cur.next;
                break;
            }
            Last = cur;
            ++i;
        }
        return head;
    }
}