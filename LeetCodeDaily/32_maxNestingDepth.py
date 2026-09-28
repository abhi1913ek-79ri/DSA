# 1614. Maximum Nesting Depth of the Parentheses
def solve(s):
    cnt = 0
    depth = 0
    for ch in s:
        if ch == '(':
            cnt += 1
        elif ch == ')':
            depth = max(depth,cnt)
            cnt -= 1
    return depth

def main():
    s = input()
    print(solve(s))

if __name__ == "__main__":
    main()