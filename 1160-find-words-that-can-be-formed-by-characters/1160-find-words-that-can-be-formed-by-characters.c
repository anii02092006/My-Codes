int countCharacters(char** words, int wordsSize, char* chars) {
    int freq[26] = {0};
    int total = 0;

    // Count frequency of chars
    for (int i = 0; chars[i]; i++) {
        freq[chars[i] - 'a']++;
    }

    // Check each word
    for (int i = 0; i < wordsSize; i++) {
        int temp[26] = {0};
        int good = 1;

        for (int j = 0; words[i][j]; j++) {
            int idx = words[i][j] - 'a';
            temp[idx]++;
            if (temp[idx] > freq[idx]) {
                good = 0;
                break;
            }
        }

        if (good) {
            total += strlen(words[i]);
        }
    }

    return total;
}
