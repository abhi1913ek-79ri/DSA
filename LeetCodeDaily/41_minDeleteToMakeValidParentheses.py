# LC-301. Remove Invalid Parentheses

def solve(op, idx, s, open_count, rem_open, rem_close, st):

    # Invalid prefix
    if open_count < 0:
        return

    # Not enough characters left to remove
    if rem_open + rem_close > len(s) - idx:
        return

    # Base condition
    if idx == len(s):

        if open_count == 0 and rem_open == 0 and rem_close == 0:
            st.add(op)

        return

    ch = s[idx]

    # Non-parenthesis character
    if ch != '(' and ch != ')':

        op += ch

        solve(op, idx + 1, s,
              open_count,
              rem_open,
              rem_close,
              st)

    # '('
    elif ch == '(':

        # OPTION 1: Remove '('
        if rem_open > 0:

            solve(op, idx + 1, s,
                  open_count,
                  rem_open - 1,
                  rem_close,
                  st)

        # OPTION 2: Keep '('
        solve(op + ch, idx + 1, s,
              open_count + 1,
              rem_open,
              rem_close,
              st)

    # ')'
    else:

        # OPTION 1: Remove ')'
        if rem_close > 0:

            solve(op, idx + 1, s,
                  open_count,
                  rem_open,
                  rem_close - 1,
                  st)

        # OPTION 2: Keep ')'
        if open_count > 0:

            solve(op + ch, idx + 1, s,
                  open_count - 1,
                  rem_open,
                  rem_close,
                  st)


def remove_invalid_parentheses(s):

    rem_open = 0
    rem_close = 0

    # Calculate minimum removals
    for ch in s:

        if ch == '(':
            rem_open += 1

        elif ch == ')':

            if rem_open > 0:
                rem_open -= 1
            else:
                rem_close += 1

    st = set()

    solve("", 0, s,
          0,
          rem_open,
          rem_close,
          st)

    # Deterministic output
    ans = sorted(st)

    return ans


def main():

    s = input().strip()

    ans = remove_invalid_parentheses(s)

    for string in ans:
        print(string)


if __name__ == "__main__":
    main()