class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode tmp = head;
        int listSize = 0, sz = 0;
        for(; tmp != null; tmp = tmp.next) listSize++;
        for(tmp = head; tmp != null && listSize/2 != sz; tmp = tmp.next, sz++);
        return tmp;
    }
}