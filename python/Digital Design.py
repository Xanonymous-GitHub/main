def tc():
    def a(x): return x ** 5 + 2
    print(a)
    print(a(2))
    print(a(12))
    score = int(input())


def main():
    _input = input()
    return tc()


if __name__ == "__main__":
    main()
