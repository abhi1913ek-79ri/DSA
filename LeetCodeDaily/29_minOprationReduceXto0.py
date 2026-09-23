# 1658. Minimum Operations to Reduce X to Zero

# Better
def solve1(nums,x):
    n = len(nums);

    s = sum(nums);

    target = s-x;
    if target < 0 :
        return -1;

    mpp = {};

    mpp[0] = -1;
    pre = 0;
    maxLen = 0;

    for i in range(n):
        pre += nums[i];

        need = pre - target;

        if mpp.get(need) is not None:
            maxLen = max(maxLen,i-mpp[need]);

        if mpp.get(need) is None:
            mpp[pre] = i;

    if target != 0 and maxLen==0:
        return -1;

    return n - maxLen;
    # TC = O(n)
    # SC = O(n)

# Optimal
def solve2():
    pass

def main():
    n = int(input());
    nums = list(map(int,input().split()));
    x = int(input());
    print(solve1(nums,x));

main()