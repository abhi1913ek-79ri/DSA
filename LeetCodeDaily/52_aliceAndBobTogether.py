# LC: 2409. Count Days Spent Together
def solve(aa,la,ab,lb):
    months = [31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31]
    def dayNumber(date):
        month = int(date[:2])
        day = int(date[3:])
        return sum(months[:month-1])+day
    start = max(dayNumber(aa),dayNumber(ab))
    end = min(dayNumber(la),dayNumber(lb))

    return max(0,end-start+1)

def main():
    aa = input()
    la = input()

    ab = input()
    lb = input()

    print(solve(aa,la,ab,lb))

if __name__ == "__main__":
    main()