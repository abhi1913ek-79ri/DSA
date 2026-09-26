# 1807. Evaluate the Bracket Pairs of a String
def solve(s,knowledge):
    n = len(s);
    # key val mapping
    mpp = {};
    for  key,val in knowledge:
        mpp[key] = val;
        
    ans  = "";
    i = 0;
    while i < n:
        if s[i] == '(':
            i += 1;
            key = "";
            while s[i] != ')':
                key += s[i];
                i += 1;
            i += 1;
            if mpp.get(key) is not None:
                ans += mpp[key];
            else :
                ans += '?';
        else:
            ans += s[i];
            i += 1;
    return ans;

def main():
    s = input()
    n = int(input())

    knowledge = []

    for _ in range(n):
        key , val = input().split()
        knowledge.append([key,val])

    print(solve(s,knowledge))


if __name__ == "__main__":
    main();