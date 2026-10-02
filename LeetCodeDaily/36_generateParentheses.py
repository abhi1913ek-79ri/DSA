# LC :  22. Generate Parentheses
def solve(op,open,close,ans):
    if open == 0 and close == 0:
        ans.append(op)
        return
    # open
    if open > 0:
        solve(op+'(',open-1,close,ans)
        
    if close > open:
        solve(op+')',open,close-1,ans)
        
def generateParenthesis(n):
    ans =[]
    solve("",n,n,ans)
    return ans


def main():
    n = int(input())
    ans = generateParenthesis(n)
    ans.sort()
    for ele in ans:
        print(ele,end=" ")

if __name__ == "__main__":
    main()