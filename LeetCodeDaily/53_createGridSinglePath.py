# LC:3963. Create Grid With Exactly One Path
def solve(m,n):
    firstRow = "."*n
    ans = [firstRow]
    ans.extend(["#"*(n-1)+"."]*(m-1))
    return ans

def main():
    m,n=list(map(int,input().split()))
    ans = solve(m,n)
    for row in ans:
        print(row)

if __name__ == "__main__":
    main()
   