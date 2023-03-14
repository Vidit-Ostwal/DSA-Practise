# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import Optional


class Solution:
    def Helper(self,root: Optional[TreeNode], temp_sum : int) -> int:
        
        if (root.left == None and root.right == None):
            return temp_sum*10 + root.val

        total_sum = 0
        
        if (root.left != None):
            total_sum += self.Helper(root.left,temp_sum*10 + root.val)
        
        if (root.right != None):
            total_sum += self.Helper(root.right,temp_sum*10 + root.val)
        
        return total_sum


    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        return self.Helper(root,0)
        