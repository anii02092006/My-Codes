#include <stddef.h>
#include <stdint.h>

#define MOD 1000000007

int countPermutations(int* complexity, int complexitySize) {
    if (complexitySize <= 1) {
        // Only computer 0 exists — 1 way (do nothing / it's already unlocked)
        return 1;
    }

    int root = complexity[0];
    // Check if every other computer can be unlocked (i.e. has strictly greater complexity than root)
    for (int i = 1; i < complexitySize; i++) {
        if (complexity[i] <= root) {
            // If any computer has complexity <= complexity[0], it's impossible to unlock it
            return 0;
        }
    }

    // If all are unlockable, the number of valid permutations = (n-1)! modulo MOD
    int64_t ans = 1;
    for (int i = 1; i < complexitySize; i++) {
        ans = (ans * i) % MOD;
    }
    return (int) ans;
}
