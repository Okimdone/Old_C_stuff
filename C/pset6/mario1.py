from cs50 import get_int

def main():
    A=get_int("enter a number")

    for i in range(A):
        for j in range(A-i):
            print("#",end="")

        print()

if __name__ == "__main__":
    main()