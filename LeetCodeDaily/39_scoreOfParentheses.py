# LC - 856. Score of Parentheses
def solve(s):
    n = len(s)
    depth = 0
    res = 0
    for i,ch in enumerate(s):
        if ch == '(':
            depth += 1
        else :
            depth -= 1

            if s[i-1] == '(':
                res += pow(2,depth)
    return res

def main():
    try:
        s = input()
    except EOFError:
        s = ""

    print(solve(s))

if __name__ == "__main__":
    main()
