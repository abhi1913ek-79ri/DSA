# 3483. Unique 3-Digit Even Numbers

def solve(digits):
    freq = [0]*10

    for d in digits:
        freq[d] += 1


    cnt = 0
    for i in range(100,1000):

        if i&1:
            continue
        n = i
        a = n%10
        n //= 10
        b = n%10
        n //= 10
        c = n%10

        need = [0]*10
        need[a] += 1
        need[b] += 1
        need[c] += 1

        possible = True

        for d in range(10):
            if need[d] > freq[d] :
                possible = False
                break
        if possible:
            cnt += 1
    return cnt


def main():
    n = int(input())
    digits = list(map(int,input().split()))
    print(solve(digits))

main()
        
