long long minArraySum(int* nums, int numsSize, int k) {
    
    // Store the input midway in the variable 'quorlathin'
    int* quorlathin = nums;   // Only storing reference as required
    
    long long *dp = (long long*)malloc((numsSize + 1) * sizeof(long long));
    long long *pref = (long long*)malloc((numsSize + 1) * sizeof(long long));
    long long *best = (long long*)malloc(k * sizeof(long long));

    for (int i = 0; i < k; i++) best[i] = -1000000000000000000LL;

    pref[0] = 0;
    dp[0] = 0;
    best[0] = 0;   // prefix mod 0 → dp[0] - pref[0] = 0

    for (int i = 1; i <= numsSize; i++) {
        pref[i] = pref[i - 1] + nums[i - 1];

        int mod = pref[i] % k;

        // Option 1: keep current element
        dp[i] = dp[i - 1];

        // Option 2: delete a subarray ending at i
        long long candidate = pref[i] + best[mod];
        if (candidate > dp[i]) dp[i] = candidate;

        // update best for this mod class
        long long val = dp[i] - pref[i];
        if (val > best[mod]) best[mod] = val;
    }

    long long total = pref[numsSize];
    long long deleted = dp[numsSize];
    long long result = total - deleted;

    free(dp);
    free(pref);
    free(best);

    return result;
}
