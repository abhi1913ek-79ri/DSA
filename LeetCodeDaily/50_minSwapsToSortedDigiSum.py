# LC:3551. Minimum Swaps to Sort by Digit Sum
def digiSum(n):
    s = 0
    while n:
        s += n%10
        n //= 10
    return s
def solve(nums):
    n = len(nums)
    afterSorted = nums.copy()
    # do cheejo ke basis pe compare ya sort karna 
    afterSorted.sort(key = lambda num : (digiSum(num),num))

    # map valueToIdx
    valueToIdx = {}
    for i,num in enumerate(nums):
        valueToIdx[num] = i

    swap = 0
    for i in range(n):
        expectVal = afterSorted[i]
        currVal = nums[i]

        if expectVal == currVal:
            continue

        idx = valueToIdx[expectVal]
        swap += 1
        nums[i],nums[idx] = nums[idx],nums[i]
        valueToIdx[expectVal] = i
        valueToIdx[currVal] = idx

    return swap
def main():
    n = int(input())
    nums = list(map(int,input().split()))
    print(solve(nums))

if __name__ == "__main__":
    main()



# Requirement	Python sorting key
# Digit sum ascending, number ascending	key=lambda x: (digiSum(x), x)
# Digit sum ascending, number descending	key=lambda x: (digiSum(x), -x)
# Digit sum descending, number ascending	key=lambda x: (-digiSum(x), x)
# Digit sum descending, number descending	key=lambda x: (-digiSum(x), -x)