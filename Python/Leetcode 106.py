# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from ast import List


class Solution:
    def Helper(self,inorder: List[int],postorder: List[int], st1, ed1, st2, ed2):
        
        if st1 == ed1 or st2 == ed2:
            return TreeNode(inorder[st1])
        
        if st1 > ed1 or st2 > ed2:
            return None
        
        root_value = postorder[ed2]
        index = inorder.index(root_value)

        Root = TreeNode(root_value)
        left_length = index - 1 - st1

        Root.left = self.Helper(inorder, postorder, st1, index - 1, st2, st2 + left_length)
        Root.right = self.Helper(inorder,postorder, index + 1, ed1, st2 + left_length + 1, ed2 - 1)

        return Root 

        
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        return self.Helper(inorder,postorder,0,len(inorder)-1,0,len(postorder)-1)
