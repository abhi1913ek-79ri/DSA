# 2267. Check if There Is a Valid Parentheses String Path

def solve(i, j, openCnt, grid, n, m, dp):

    openCnt += 1 if grid[i][j] == '(' else -1

    # invalid prefix
    if openCnt < 0:
        return False

    # destination
    if i == n - 1 and j == m - 1:
        return openCnt == 0

    # remaining cells
    remaining = n - 1 - i + m - 1 - j

    if openCnt > remaining:
        return False

    # already calculated
    if dp[i][j][openCnt] != -1:
        return dp[i][j][openCnt]

    # move down
    if i + 1 < n and solve(i + 1, j, openCnt, grid, n, m, dp):
        dp[i][j][openCnt] = 1
        return True

    # move right
    if j + 1 < m and solve(i, j + 1, openCnt, grid, n, m, dp):
        dp[i][j][openCnt] = 1
        return True

    dp[i][j][openCnt] = 0
    return False


def hasValidPath(grid):

    n = len(grid)
    m = len(grid[0])

    if grid[0][0] == ')' or grid[n - 1][m - 1] == '(':
        return False

    # path length must be even
    if (n + m - 1) & 1:
        return False

    dp = [
        [
            [-1] * (n + m + 1)
            for _ in range(m)
        ]
        for _ in range(n)
    ]

    return solve(0, 0, 0, grid, n, m, dp)


def main():

    n = int(input())

    grid = []

    for i in range(n):

        m = int(input())

        row = list(input().strip())

        grid.append(row)

    print(int(hasValidPath(grid)))


if __name__ == "__main__":
    main()