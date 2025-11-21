#include <stdio.h>
int main() {
    int n, key, arr[100], i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &key);
    for(i = 0; i < n; i++)
        if(arr[i] == key) {
            printf("Found");
            return 0;
        }
    printf("Not Found");
    return 0;
}
