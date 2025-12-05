class Solution:
    def countPartitions(self, nums):
        total = sum(nums)
        n = len(nums)

        if total % 2 == 1:
            return 0    # no valid partitions

        return n - 1    # all partitions are valid

        