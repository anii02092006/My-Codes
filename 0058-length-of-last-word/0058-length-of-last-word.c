#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char * s) {
    int len = strlen(s);
    int length = 0;
    int i = len - 1;

    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ') i--;

    // Count the last word
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}
