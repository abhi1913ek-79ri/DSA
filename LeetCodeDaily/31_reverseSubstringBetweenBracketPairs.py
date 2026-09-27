# 1190. Reverse Substrings Between Each Pair of Parentheses

def solve(s):
    st = [""]

    for ch in s:
        if ch == '(':
            st.append("")
        elif ch == ')':
            top = st.pop()
            st[-1] += top[::-1]
        else:
            st[-1] += ch

    return st[-1]
    # TC = O(n)
    # SC = O(n)

def main():
    s = input()
    print(solve(s))

if __name__ == "__main__":
    main()