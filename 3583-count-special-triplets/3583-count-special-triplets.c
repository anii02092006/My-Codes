int specialTriplets(int* nums, int numsSize) {
    const int MOD = 1000000007;
    const int MAXV = 200005;   // to cover 2 * nums[i]

    long long leftFreq[MAXV];
    long long rightFreq[MAXV];

    // Initialize frequency arrays
    for (int i = 0; i < MAXV; i++) {
        leftFreq[i] = 0;
        rightFreq[i] = 0;
    }

    // Build right frequency counts
    for (int i = 0; i < numsSize; i++) {
        rightFreq[nums[i]]++;
    }

    long long ans = 0;

    for (int j = 0; j < numsSize; j++) {
        int x = nums[j];
        rightFreq[x]--;   // remove current j from right side

        int target = 2 * x;
        if (target < MAXV) {
            ans = (ans + (leftFreq[target] * rightFreq[target]) % MOD) % MOD;
        }

        leftFreq[x]++;    // add nums[j] to left side
    }

    return (int)ans;
}
