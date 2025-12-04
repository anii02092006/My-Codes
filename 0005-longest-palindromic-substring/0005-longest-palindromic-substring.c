char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n < 2) return s;

    int start = 0, maxLen = 1;

    for (int i = 0; i < n; i++) {
        int left = i, right = i;

        // Odd length
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        int len1 = right - left - 1;

        // Even length
        left = i;
        right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        int len2 = right - left - 1;

        int len = (len1 > len2) ? len1 : len2;

        if (len > maxLen) {
            maxLen = len;
            start = i - (len - 1) / 2;
        }
    }

    char* res = (char*)malloc(maxLen + 1);
    strncpy(res, s + start, maxLen);
    res[maxLen] = '\0';

    return res;
}

