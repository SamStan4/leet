class Solution:
    def isValidSudoku(self, board: list[list[str]]) -> bool:
        row_a : list[list[bool]] = [[True for _ in range(0, 9, 1)] for _ in range(0, 9, 1)]
        col_a : list[list[bool]] = [[True for _ in range(0, 9, 1)] for _ in range(0, 9, 1)]
        sub_a : list[list[bool]] = [[True for _ in range(0, 9, 1)] for _ in range(0, 9, 1)]
        for i in range(0, 9, 1):
            for j in range(0, 9, 1):
                if board[i][j] == ".":
                    continue
                num = int(board[i][j]) - 1
                if (row_a[i][num]) and (col_a[j][num]) and (sub_a[((i // 3) * 3) + (j // 3)][num]):
                    row_a[i][num] = False
                    col_a[j][num]=  False
                    sub_a[((i // 3) * 3) + (j // 3)][num] = False
                else:
                    return False
        return True
