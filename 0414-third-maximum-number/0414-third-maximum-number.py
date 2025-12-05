from typing import List

class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        first = second = third = float('-inf')
        found = set()  # To track distinct numbers
        
        for num in nums:
            if num in found:
                continue
            found.add(num)
            
            if num > first:
                third = second
                second = first
                first = num
            elif num > second:
                third = second
                second = num
            elif num > third:
                third = num
        
        return third if len(found) >= 3 else first
