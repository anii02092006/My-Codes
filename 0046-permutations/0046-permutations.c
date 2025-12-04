#include <stdlib.h>
#include <stdbool.h>

void backtrack(int* nums, int numsSize, bool* used, int* path, int depth, int** result, int* returnSize) {
    if (depth == numsSize) {
        for (int i = 0; i < numsSize; i++) {
            result[*returnSize][i] = path[i];
        }
        (*returnSize)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (used[i]) continue;
        path[depth] = nums[i];
        used[i] = true;
        backtrack(nums, numsSize, used, path, depth + 1, result, returnSize);
        used[i] = false;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int maxPerms = 1;
    for (int i = 2; i <= numsSize; i++) maxPerms *= i;

    int** result = (int**)malloc(maxPerms * sizeof(int*));
    for (int i = 0; i < maxPerms; i++) {
        result[i] = (int*)malloc(numsSize * sizeof(int));
    }

    *returnColumnSizes = (int*)malloc(maxPerms * sizeof(int));
    for (int i = 0; i < maxPerms; i++) (*returnColumnSizes)[i] = numsSize;

    int* path = (int*)malloc(numsSize * sizeof(int));
    bool* used = (bool*)calloc(numsSize, sizeof(bool));
    *returnSize = 0;

    backtrack(nums, numsSize, used, path, 0, result, returnSize);

    free(path);
    free(used);

    return result;
}
