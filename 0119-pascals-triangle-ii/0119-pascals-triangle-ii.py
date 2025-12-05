class Solution:
    def getRow(self, rowIndex: int) -> list[int]:
        row = [1]  # First element
        
        for i in range(1, rowIndex + 1):
            # Compute new element using previous element
            row.append(row[i-1] * (rowIndex - i + 1) // i)
        
        return row

        