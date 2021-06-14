/**
https://www.interviewbit.com/problems/populate-next-right-pointers-tree/
Given a binary tree
struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
}
Populate each next pointer to point to its next right node.
If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.
Note: You may only use constant extra space.
Example :
Given the following binary tree,
     1
   /  \
  2    3
 / \  / \
4  5  6  7
After calling your function, the tree should look like:
     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \  / \
4->5->6->7 -> NULL
Note 1: that using recursion has memory overhead and does not qualify for constant space.
Note 2: The tree need not be a perfect binary tree. 
**/
void Solution::connect(TreeLinkNode* A) {
  TreeLinkNode *wall = nullptr, *prev = nullptr;
  TreeLinkNode *cur = A;
  while(cur) {
    while(cur) {
      if(cur->left) {
        if(prev)
          prev->next = cur->left;
        else
          wall = cur->left;
        prev = cur->left;
      }
      if(cur->right) {
        if(prev)
          prev->next = cur->right;
        else
          wall = cur->right;
        prev = cur->right;
      }
      cur = cur->next;
    }
    cur = wall;
    wall = nullptr;
    prev = nullptr;
  }
}
