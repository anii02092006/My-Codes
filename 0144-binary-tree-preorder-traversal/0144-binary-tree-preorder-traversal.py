class Solution:
    def preorderTraversal(self, root):
        result = []

        def dfs(node):
            if not node:
                return
            result.append(node.val)   # root
            dfs(node.left)           # left
            dfs(node.right)          # right

        dfs(root)
        return result
        