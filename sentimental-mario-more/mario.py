
def main():
    while True:
        height = int(input("Enter height: "))
        if (height >= 0):
            break
    mario(height)
    return 0

def mario(height):
    for i in range(height-1, -1, -1):
        print(" " * i, end="")
        for j in range(height-i):
            print("#", end="")
        print("  ", end="")
        for k in range(height-i):
            print("#", end="")
        print()

if __name__ == "__main__":
    main()
