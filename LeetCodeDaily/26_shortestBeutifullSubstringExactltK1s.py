def solve(s,k):
    n = len(s)

    bestLen = float('inf')
    ans = ""
    ones = 0

    l = 0

    for r in range(n):
        if s[r] == '1':
            ones += 1

        while ones >= k:

            if ones == k:
                currLen = r-l+1
                curr = s[l:r+1]
                if currLen < bestLen:
                    bestLen = currLen
                    ans = curr
                elif currLen == bestLen:
                    ans = min(ans,curr)
            if s[l] == '1':
                ones -= 1
            l += 1
    return ans


def main():
    s = input()
    k = int(input())

    print(solve(s,k))

main()
    