/**
https://www.interviewbit.com/problems/remove-half-nodes/
Given a binary tree A with N nodes.
You have to remove all the half nodes and return the final binary tree.
NOTE:
Half nodes are nodes which have only one child.
Leaves should not be touched as they have both children as NULL.
Problem Constraints
1 <= N <= 105
Input Format
First and only argument is an pointer to the root of binary tree A.
Output Format
Return a pointer to the root of the new binary tree.
Example Input
Input 1:
     1
   /   \
  2     3
 / 
4
Input 2:
      1
    /   \
   2     3
  / \     \
 4   5     6
Example Output
Output 1:
   1
 /   \
4     3
Output 2:
    1
  /   \
 2     6
/ \
4   5
Example Explanation
Explanation 1: The only half node present in the tree is 2 so we will remove this node.
Explanation 2: The only half node present in the tree is 3 so we will remove this node.
**/
TreeNode* Solution::solve(TreeNode* A) {
  if(A->left == NULL && A->right == NULL)return A;
  if(A->left == NULL)
    return solve(A->right);
  if(A->right == NULL)
    return solve(A->left);
  A->left = solve(A->left);
  A->right = solve(A->right);
  return A;   
}
