# LC - 3644. Maximum K to Sort a Permutation
def solve(nums):
    n = len(nums)

    K = -1 # all bits set

    for i,num in enumerate(nums):
        if i != num :
            K &= num

    return 0 if K == -1 else K
    # TC = O(n)
    # SC = O(1)

def main():
    n = int(input())
    nums = list(map(int,input().split()))
    print(solve(nums))

if __name__ == "__main__":
    main()