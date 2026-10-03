# 37_longestValidParentheses
def solve(s):
    n = len(s)

    maxLen = 0
    open = 0
    close = 0
    # left to right
    for ch in s:
        open += int(ch == '(')
        close += int(ch == ')')

        if open > close:
            continue
        elif close > open:
            open , close = 0,0
        else:
            maxLen = max(maxLen,open+close)

    open = 0
    close = 0
    # right to left
    for ch in s[::-1]:
        open += int(ch == '(')
        close += int(ch == ')')
    
        if close > open:
            continue
        elif open > close:
            open , close = 0,0
        else:
            maxLen = max(maxLen,open+close)

    return maxLen
    # TC = O(n)
    # Sc = O(1)
    

    
        

def main():
    try:
        s = input()
    except EOFError:
        s = ""
    print(solve(s))

if __name__ == "__main__":
    main()