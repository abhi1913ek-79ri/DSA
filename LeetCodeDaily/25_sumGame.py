def solve(num):
    n = len(num)
    mid = n/2
    s1 = 0
    s2 = 0
    q = 0
    totalQ = 0
    for i in range(n):
        ch = num[i]
        if i < mid :
            if ch == '?' :
                q += 1
                totalQ += 1
            else:
                s1 += int(ch)
        else:
            if ch == '?' :
                q -= 1
                totalQ += 1
            else:
                s2 += int(ch)
    
    if totalQ&1 :
        return True
    
    return 2*(s1-s2) != -9*q


def main():
    num = input()
    print(solve(num))

main()