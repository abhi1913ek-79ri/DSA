# 1541. Minimum Insertions to Balance a Parentheses String
def minInsertions(s):
    ans = 0
    need = 0

    for ch in s:
        if ch == '(':
            if need%2 == 1:
                ans += 1
                need -= 1
            need += 2
        else:
            need -= 1
            if need < 0:
                ans += 1
                need = 1
        

    return ans + need


def main():
    try:
        s = input()
    except EOFError:
        s = ""

    print(minInsertions(s))


if __name__ == "__main__":
    main()
