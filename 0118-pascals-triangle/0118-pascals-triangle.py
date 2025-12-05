class Solution:
    def generate(self, numRows: int) -> list[list[int]]:
        if numRows == 0:
            return []

        triangle = [[1]]  # First row

        for i in range(1, numRows):
            prev_row = triangle[i-1]
            row = [1]  # First element
            # Compute middle elements
            for j in range(1, i):
                row.append(prev_row[j-1] + prev_row[j])
            row.append(1)  # Last element
            triangle.append(row)

        return triangle

        