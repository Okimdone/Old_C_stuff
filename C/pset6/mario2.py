from cs50 import get_int

def main():

    A=get_int("Enter a number : ")

    for i in range(A):
        for s in range(A - i):
            print(" ",end="")

        for j in range(i + 1):
            print("#",end="")

        print()


if __name__ == "__main__":
    main()