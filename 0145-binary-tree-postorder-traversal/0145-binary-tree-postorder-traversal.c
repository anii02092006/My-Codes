/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void helper(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL) return;

    helper(root->left, arr, index);   // Left
    helper(root->right, arr, index);  // Right
    
    arr[*index] = root->val;          // Root
    (*index)++;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    // Maximum possible nodes = 100 (from constraints)
    int* result = (int*)malloc(sizeof(int) * 100);

    *returnSize = 0;
    helper(root, result, returnSize);

    return result;
}
