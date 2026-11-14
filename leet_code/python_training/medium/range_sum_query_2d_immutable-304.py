class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        ROWS, COLS = len(matrix), len(matrix[0])
        self.prefixSum = [[0] * (COLS+1) for _ in range(ROWS+1)]

        for r in range(1,ROWS+1):
            prefix = 0
            for c in range(1,COLS+1):
                prefix+= matrix[r-1][c-1]
                self.prefixSum[r][c] = self.prefixSum[r-1][c] + prefix


    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        r1, c1, r2, c3 = row1+1, col1+1, row2+1, col2+1

        bottomRight = self.prefixSum[r2][c2]
        top = self.prefixSum[r1-1][c2]
        left = self.prefixSum[r2][c1-1]
        topLeft = self.prefixSum[r1-1][c1-1]

        return bottomRight - top - left +topLeft


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)