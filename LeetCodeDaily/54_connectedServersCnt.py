# 1267. Count Servers that Communicate

def solve(grid):
    n = len(grid)
    m = len(grid[0])

    row = [0] * n
    col = [0] * m

    for i in range(n):
        for j in range(m):
            if grid[i][j] == 1:
                row[i] += 1
                col[j] += 1

    cnt = 0

    for i in range(n):
        for j in range(m):
            if grid[i][j] == 1 and (row[i] >= 2 or col[j] >= 2):
                cnt += 1

    return cnt

    # TC = O(n*m)
    # SC = O(n+m)


def main():
    n = int(input())

    grid = []

    for i in range(n):
        m = int(input())
        row = list(map(int, input().split()))
        grid.append(row)

    print(solve(grid))


if __name__ == "__main__":
    main()
