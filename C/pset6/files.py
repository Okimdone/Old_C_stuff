import time

def main():
    while True:
        N = int(input("N :"))
        if N >= 2 and N <=50:
            break

    while True:
        K = int(input("K :"))
        if K >= 0 and K <= N* (N - 1) / 2:
            break

    start = time.clock()
    string = make_string(N , K)
    print time.clock() - start

    print("%s %i" % (string,endtime - starttime))



def make_string(n , k):

    base=n
    half_n=n/2
    As=0

    while As*base < k:
        if base < half_n:
            return ""
        As=As+1
        base-=1

    AB=""
    if As*base == k:
        for i in range(As):
            AB += "A"
        for i in range(As,n):
            AB += "B"
    else:
        for i in range(As - 1):
            AB += "A"
        for i in range(As - 1,n):
            AB += "B"

        position_of_last_A = As*(1 + base) - (k + 1)
        AB = AB[:position_of_last_A] + "A" + AB[position_of_last_A +  1:]

    return AB


if __name__ == "__main__":
    main()