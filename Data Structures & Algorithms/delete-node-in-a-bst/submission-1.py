# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        # 1. Base Case
        if not root:
            return None

        # 2. Search for the node to delete
        if key < root.val:
            root.left = self.deleteNode(root.left, key)
        elif key > root.val:
            root.right = self.deleteNode(root.right, key)
        
        else:
            # 3. Found the node (root.val == key)
            
            # Case A: 0 or 1 child
            if not root.left:
                return root.right
            elif not root.right:
                return root.left
            
            # Case B: Two children
            # Find the Inorder Successor (smallest in the right subtree)
            
            # FIX: Start searching from the right child
            min_node = root.right 
            
            # Keep going left to find the smallest value
            while min_node.left:
                min_node = min_node.left
            
            # Replace current value with successor's value
            root.val = min_node.val
            
            # Delete the duplicate successor from the right subtree
            root.right = self.deleteNode(root.right, min_node.val)
            
        return root