import sys

def isSafe(self, matrix, x, y):
    row = len(matrix)
    col = len(matrix[0])
    if x < 0 or x > col or y > row or y < 0:
        return False
    return True


def dfs(self, matrix, dp, x, y):
    if dp[y][x]:
        return dp[y][x]
    answer = 1
    search_arr = [(-1,0),(0,1),(1,0),(0,-1)]
    for i in search_arr:
        y_next, x_next = y + i[0], x + i[1]
        if isSafe(matrix, x_next, y_next) and dp[y_next][x_next]:
            answer = max(answer,dfs(matrix, dp, x_next, y_next))
    dp[y][x] = answer

def longestIncreasingPath(self, matrix):
    """
    :type matrix: List[List[int]]
    :rtype: int
    """
    row = len(matrix)
    if (row == 0):
        return 0
    col = len(matrix[0])
    DP = [[0 for i in range(col)] for j in range(row)]
    for i in range(row):
        for j in range(col):
            if dp[i][j] != 0:
                continue
            else:
                dfs()

if __name__ == __main__:
    