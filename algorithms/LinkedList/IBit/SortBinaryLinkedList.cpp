/**
Given a Linked List A consisting of N nodes.
The Linked List is binary i.e data values in the linked list nodes consist of only 0's and 1's.
You need to sort the linked list and return the new linked list.
NOTE:Try to do it in constant space.
Problem Constraints 1 <= N <= 105
A.val = 0 or A.val = 1
Input Format
First and only argument is the head pointer of the linkedlist A.
Output Format
Return the head pointer of the new sorted linked list.
Example Input
Input 1: 1 -> 0 -> 0 -> 1
Input 2: 0 -> 0 -> 1 -> 1 -> 0
Example Output
Output 1: 0 -> 0 -> 1 -> 1
Output 2: 0 -> 0 -> 0 -> 1 -> 1
Example Explanation
Explanation 1: The sorted linked list looks like: 0 -> 0 -> 1 -> 1
Explanation 2: The sorted linked list looks like: 0 -> 0 -> 0 -> 1 -> 1
**/
ListNode* Solution::solve(ListNode* A) {
  ListNode *ones = new ListNode(0), *oneCur = ones;
  ListNode *zeros = new ListNode(0), *zeroCur = zeros;
  ListNode *cur = A;
  while(cur) {
    if(cur->val == 0) {
      zeroCur->next = cur;
      zeroCur = zeroCur->next;
    }
    else {
      oneCur->next = cur;
      oneCur = oneCur->next;
    }
    cur = cur->next;
  }
  oneCur->next = nullptr;
  zeroCur->next = ones->next;
  return zeros->next;
}
