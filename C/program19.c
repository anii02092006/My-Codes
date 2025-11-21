#include <stdio.h>
int main() {
    int a, b, l;
    scanf("%d %d", &a, &b);
    l = (a > b) ? a : b;
    while(1) {
        if(l % a == 0 && l % b == 0) {
            printf("%d", l);
            break;
        }
        l++;
    }
    return 0;
}
