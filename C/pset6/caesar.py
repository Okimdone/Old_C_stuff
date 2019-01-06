from cs50 import get_string
import sys

def main():
    if len(sys.argv) != 2:
        print("enter the key as a non negative number argument as an arg!!!")
        return 1


    k = int(sys.argv[1])

    if k <= 0 :
        print("enter the key as a non negative number argument ")
        return 2

    print("type the text to cipher :")

    s = get_string()

    for c in s:
        ascii = ord(c)

        if ascii >= ord('A') and ascii <= ord('Z'):
            ascii += k
            while ascii > ord('Z'):
                ascii -= 26;

        elif ascii >= ord('a') and ascii <= ord('z'):
            ascii += k
            while ascii > ord('z'):
                ascii -= 26;


        print(f"{chr(ascii)}", end="")

    print()


if __name__ == "__main__":
    main()