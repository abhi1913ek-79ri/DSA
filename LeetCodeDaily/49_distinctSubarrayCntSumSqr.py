# 2913. Subarrays Distinct Element Sum of Squares I
def solve(nums):
    n = len(nums)
    ans = 0
    for i in range(n):
        st = set()
        for j in range(i,n):
            st.add(nums[j])
            size = len(st)
            ans += size*size
    return ans
    # TC = O(n*n)
    # SC = O(n)

def main():
    n = int(input())
    nums = list(map(int,input().split()))
    print(solve(nums))

if __name__ == "__main__":
    main()