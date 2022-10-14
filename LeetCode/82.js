/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var deleteDuplicates = function(head) {
  let cur = new ListNode();
  const res = cur;

  if (head === null) return null;

  let prev = head.val, cnt = 1;
  head = head.next;

  if (head === null) {
    cur.val = prev;
    return res;
  }

  while (head) {
    if (prev === head.val) cnt++;
    else {
      if (cnt == 1) {
        cur.next = new ListNode(prev);
        cur = cur.next;
      }
      
      prev = head.val;
      cnt = 1;
    }

    head = head.next;
  }

  if (cnt === 1) {
    cur.next = new ListNode(prev);
  }

  return res.next;
};