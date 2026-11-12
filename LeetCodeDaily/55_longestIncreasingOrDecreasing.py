def longestMonotonicSubarray(nums):
    n = len(nums)

    maxLen = 1
    currLen = 1

    # Strictly Increasing
    for i in range(1, n):
        if nums[i - 1] < nums[i]:
            currLen += 1
            maxLen = max(maxLen, currLen)
        else:
            currLen = 1

    currLen = 1

    # Strictly Decreasing
    for i in range(1, n):
        if nums[i - 1] > nums[i]:
            currLen += 1
            maxLen = max(maxLen, currLen)
        else:
            currLen = 1

    return maxLen


if __name__ == "__main__":
    n = int(input())
    nums = list(map(int, input().split()))
    print(longestMonotonicSubarray(nums))