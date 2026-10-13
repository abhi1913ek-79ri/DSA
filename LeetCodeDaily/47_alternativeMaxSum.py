# LC : 3727. Maximum Alternating Sum of Squares
def solve(nums):
    n = len(nums)
    nums = list(map(lambda x: x*x,nums))
    nums.sort()
    ans = 0
    for i , sqr in enumerate(nums):
        if i < n//2:
            ans -= sqr
        else:
            ans += sqr

    return ans
    # TC = O(nlogn)
    # SC = O(1)

def main():
    n = int(input())
    nums = list(map(int,input().split()))
    print(solve(nums))

if __name__ == "__main__":

    main()