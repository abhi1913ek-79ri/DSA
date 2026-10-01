# LC 20. Valid Parentheses
def solve(s):
    st = []
    mpp = {
        '{':'}',
        '(':')',
        '[':']'
    }
    for ch in s:
        if ch in '{[(':
            st.append(ch)
        else:
            if len(st) == 0:
                return False

            top = st.pop()
            if mpp[top]  != ch:
                return False

    return len(st) == 0

def main():
    s = input()
    print(int(solve(s)))

if __name__ == "__main__":
    main()