from typing import List

class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums)
        
        # Mark numbers as negative at their corresponding index
        for num in nums:
            index = abs(num) - 1
            if nums[index] > 0:
                nums[index] = -nums[index]
        
        # Numbers whose indices are positive are missing
        result = [i + 1 for i in range(n) if nums[i] > 0]
        return result
