# 1021. Remove Outermost Parentheses
def removeOuterParentheses(s) -> str:
    ans = ""
    balance = 0
    for ch in s:
        if ch == '(' and balance:
            ans += ch
        elif ch == ')' and not ((balance-1) == 0):
            ans += ch
        if ch ==  '(':
            balance += 1
        else :
            balance -= 1
        
    return ans


def main():
    s = input()
    print(removeOuterParentheses(s))

if __name__ == "__main__":
    main()
