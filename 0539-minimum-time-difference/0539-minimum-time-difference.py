from typing import List

class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        # Convert each time to minutes
        minutes = []
        for time in timePoints:
            h, m = map(int, time.split(":"))
            minutes.append(h * 60 + m)
        
        minutes.sort()
        
        # Minimum difference between consecutive times
        min_diff = float('inf')
        for i in range(1, len(minutes)):
            min_diff = min(min_diff, minutes[i] - minutes[i-1])
        
        # Circular difference between last and first time
        min_diff = min(min_diff, 24*60 - (minutes[-1] - minutes[0]))
        
        return min_diff
