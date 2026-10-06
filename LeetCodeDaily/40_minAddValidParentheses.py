# 921. Minimum Add to Make Parentheses Valid
def minAddToMakeValid(s):
    st = []
    minOp = 0
    for ch in s:
        if ch == '(':
            st.append(ch)
        else :
            if len(st) == 0:
                minOp += 1
                continue
            st.pop()

    return len(st) + minOp

def main():
    s = input()
    print(minAddToMakeValid(s))

if __name__ == "__main__":
    main()





















