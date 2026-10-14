# 3723. Maximize Sum of Squares of Digits
def solve(num,sum):
    sumDigit = 0
    n = ""

    while num:
        if sumDigit + 9 <= sum:
            n += str(9)
            sumDigit += 9
        else:
            n += str(sum-sumDigit)
            sumDigit += sum-sumDigit
        num -= 1

    if sum != sumDigit:
        return ""

    return n
    # TC = O(n)
    # SC = O(1)
    
def main():
    num = int(input())
    sum = int(input())
    print(solve(num,sum))

if __name__ == "__main__":
    main()