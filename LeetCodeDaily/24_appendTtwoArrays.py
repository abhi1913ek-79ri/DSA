# 3069. Distribute Elements Into Two Arrays I
def solve(nums):
    arr1 = [nums[0]]
    arr2 = [nums[1]]
    n = len(nums)
    for i in range(2,n):
        l1 = arr1[-1]
        l2 = arr2[-1]
        if l1 > l2 :
            arr1.append(nums[i])
        else :
            arr2.append(nums[i])
        

    return arr1 + arr2

def printList(nums):
    flag = True
    for num in nums :
        if flag :
            print(" ",end="")
        print(num,end="")

def main():
    n = int(input())
    nums = list(map(int,input().split()))
    ans = solve(nums)
    printList(ans)


main()
