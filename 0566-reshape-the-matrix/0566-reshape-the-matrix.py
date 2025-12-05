from typing import List

class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        m = len(mat)
        n = len(mat[0])
        
        # Check if reshape is possible
        if m * n != r * c:
            return mat
        
        # Flatten the original matrix
        flat = [num for row in mat for num in row]
        
        # Build the new matrix
        reshaped = []
        for i in range(r):
            reshaped.append(flat[i*c : (i+1)*c])
        
        return reshaped
