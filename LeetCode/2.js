/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
 var addTwoNumbers = function(l1, l2) {
  let s = 0;

  let cur = new ListNode();
  const res = cur;

  while (l1 || l2) {
    if (l1) {
      s += l1.val;
      l1 = l1.next;
    }

    if (l2) {
      s += l2.val;
      l2 = l2.next;
    }

    cur.val = s%10;

    s = s > 9 ? 1 : 0;

    if (l1 || l2) {
      cur.next = new ListNode();
      cur = cur.next;
    }
  }

  if (s) cur.next = new ListNode(1);

  console.log(res);

  return res;
};