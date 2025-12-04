#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 1; // start with +1
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));

    for (int i = digitsSize - 1; i >= 0; i--) {
        int sum = digits[i] + carry;
        result[i + 1] = sum % 10; // store current digit
        carry = sum / 10;         // update carry
    }

    if (carry) {
        result[0] = carry;
        *returnSize = digitsSize + 1;
        return result;
    } else {
        // shift array to remove extra space at front
        for (int i = 0; i < digitsSize; i++)
            result[i] = result[i + 1];
        *returnSize = digitsSize;
        return result;
    }
}
