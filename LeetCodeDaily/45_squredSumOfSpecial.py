# LC-2778. Sum of Squares of Special Elements 
def sumOfSquares(nums):
    ans = 0
    n = len(nums)
    for i , num in enumerate(nums,start=1):
        if n%(i) == 0:
            ans +=num*num
    return ans


def main():
    n = int(input())
    nums = list(map(int,input().split()))
    print(sumOfSquares(nums))

if __name__ == "__main__":
    main()