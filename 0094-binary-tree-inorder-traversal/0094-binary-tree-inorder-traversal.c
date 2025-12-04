/**
 * Note: The struct TreeNode is already defined as:
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inorderHelper(struct TreeNode* root, int* result, int* returnSize) {
    if (root == NULL) return;

    inorderHelper(root->left, result, returnSize);        // left subtree
    result[(*returnSize)++] = root->val;                 // visit root
    inorderHelper(root->right, result, returnSize);      // right subtree
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* result = (int*)malloc(100 * sizeof(int)); // max nodes = 100
    inorderHelper(root, result, returnSize);
    return result;
}
