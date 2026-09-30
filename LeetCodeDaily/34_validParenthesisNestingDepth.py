# 1111. Maximum Nesting Depth of Two Valid Parentheses Strings
def solve(seq):
    ans = []
    st = []

    for ch in seq:
        if ch == '(':
            st.append(ch)
            ans.append((len(st)-1)%2)
        else :
            st.pop()
            ans.append(len(st)%2)

    return ans
    #  TC = O(n)
    #  SC = O(n)

def main():
    seq = input()
    ans = solve(seq)
    flag = False
    for ele in ans:
        if flag :
            print(" ",end="")

        print(ele,end="")
        flag = True

if __name__ == "__main__":
    main()