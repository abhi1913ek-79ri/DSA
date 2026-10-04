# 678. Valid Parenthesis String

# ALGORITHM : dp  = recursion + memo
def solve(open,idx,s,n,dp):
    if idx == n:
        return open == 0

    if dp[open][idx] != -1:
        return dp[open][idx]

    isValid = False

    if s[idx] == '(':
        isValid = solve(open+1,idx+1,s,n,dp) or isValid
    elif s[idx] == '*':
        isValid = solve(open,idx+1,s,n,dp) or isValid
        isValid = solve(open+1,idx+1,s,n,dp) or isValid
        if open > 0:
            isValid = solve(open-1,idx+1,s,n,dp) or isValid
    elif open > 0:
        isValid = solve(open-1,idx+1,s,n,dp) or isValid

    dp[open][idx] = isValid
    return isValid
    

def validParenthesesString(s):
    n = len(s)
    dp = [[-1]*(n+1) for _ in range(n+1)]

    return solve(0,0,s,n,dp)

def main():
    try :
        s = input()
    except EOFError:
        s = ""

    print(int(validParenthesesString(s)))

if __name__ == "__main__":
    main()