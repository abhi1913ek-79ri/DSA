# LC-2897. Apply Operations on Array to Maximize Sum of Squares

def maxSum(nums, k):
    n = len(nums)
    MOD = 10**9 + 7

    # Count set bits at each position
    countBit = [0] * 32

    for b in range(32):
        for num in nums:
            if num & (1 << b):
                countBit[b] += 1

    result = 0

    # Construct k maximum numbers
    while k > 0:
        curr = 0

        for b in range(32):
            if countBit[b] > 0:
                countBit[b] -= 1
                curr |= (1 << b)

        result = (result + curr * curr) % MOD
        k -= 1

    return result


def main():
    n = int(input())
    nums = list(map(int, input().split()))
    k = int(input())

    print(maxSum(nums, k))


if __name__ == "__main__":
    main()

