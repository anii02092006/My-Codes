int lengthOfLongestSubstring(char * s){
    int last[256];  // stores last index of each character
    for (int i = 0; i < 256; i++) last[i] = -1;

    int maxLen = 0;
    int start = 0;  // sliding window start index

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        // If this character was seen inside current window
        if (last[(unsigned char)c] >= start) {
            start = last[(unsigned char)c] + 1;
        }

        last[(unsigned char)c] = i;  // update last position
        int windowLen = i - start + 1;

        if (windowLen > maxLen)
            maxLen = windowLen;
    }

    return maxLen;
}
