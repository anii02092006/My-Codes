struct TreeNode* insertIntoMaxTree(struct TreeNode* root, int val) {
    // assume TreeNode is already defined
    if (root == NULL || root->val < val) {
        struct TreeNode* node = malloc(sizeof(struct TreeNode));
        node->val = val;
        node->left = root;
        node->right = NULL;
        return node;
    }
    root->right = insertIntoMaxTree(root->right, val);
    return root;
}
