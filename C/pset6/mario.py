from cs50 import get_int

def main():
    print("Enter a number!!",end=" :")
    A = get_int()

    for i in range(A):
        for j in range(i + 1):
            print("#",end="")

        print()


if __name__ == "__main__":
    main()