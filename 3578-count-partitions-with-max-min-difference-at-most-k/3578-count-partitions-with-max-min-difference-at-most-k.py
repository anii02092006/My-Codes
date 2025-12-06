from collections import deque

class Solution:
    def countPartitions(self, nums, k):
        MOD = 10**9 + 7
        n = len(nums)
        # dp[0] = 1: one way to partition empty prefix
        # pref[i] = dp[0] + dp[1] + ... + dp[i]
        dp0 = 1
        pref_prev = dp0  # pref[0]

        left = 0
        minD = deque()
        maxD = deque()

        # We'll compute dp[i] for i = 1..n
        # dp_i corresponds to ways for first i elements (nums[0..i-1])
        dp = [0] * (n + 1)  # optional if you want to inspect; dp[0] = 1
        dp[0] = 1
        pref = [0] * (n + 1)
        pref[0] = 1

        for i in range(1, n + 1):
            x = nums[i - 1]

            # add x to deques (window right end is i-1)
            while minD and minD[-1] > x:
                minD.pop()
            minD.append(x)

            while maxD and maxD[-1] < x:
                maxD.pop()
            maxD.append(x)

            # shrink left while invalid
            while maxD and minD and (maxD[0] - minD[0] > k):
                # remove nums[left] from window
                val = nums[left]
                if minD and minD[0] == val:
                    minD.popleft()
                if maxD and maxD[0] == val:
                    maxD.popleft()
                left += 1

            # now window nums[left .. i-1] is valid, so valid starts j in [left .. i-1]
            # dp[i] = sum_{j=left..i-1} dp[j] = pref[i-1] - pref[left-1]
            pref_i_minus_1 = pref[i - 1]
            pref_left_minus_1 = pref[left - 1] if left - 1 >= 0 else 0
            val_dp_i = (pref_i_minus_1 - pref_left_minus_1) % MOD

            dp[i] = val_dp_i
            pref[i] = (pref[i - 1] + dp[i]) % MOD

        return dp[n] % MOD


        