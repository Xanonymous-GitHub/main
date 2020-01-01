# UVa 725 Division
# 給一個數字n，用0~9,10個數字組成兩個5位數，使得他們的商為n，按順序輸出所有結果。


def division(db, c, m, n):
    if m == 0:
        cint = int(''.join(str(e) for e in (c[1::] if c[0] == 0 else c)))
        if sorted(list(map(int, str(cint*n)))+c) != list(range(10)):
            return
        print(cint*n, '/', ''.join(str(e) for e in c), '=', n)
        return
    for x in db:
        c.append(x)
        db.remove(c[-1])
        division(db, c, m-1, n)
        db.append(c[-1])
        db.sort()
        c.pop()


n = int(input())
division(list(range(10)), [], 5, n)
