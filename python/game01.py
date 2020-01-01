import os
import time


def main():
    m, n = map(int, (input().split()))
    x, y = 1, 1
    item = list()
    for i in range(n):
        for j in range(m):
            item.append([y, x])
            # creat map
            creatmap(item, n, m)
            time.sleep(0)
            x += 1
        y += 1
        x = 1
    # start a new board,clear all.
    input()


def creatmap(item, n, m):
    os.system('cls')
    position = [1, 1]  # position in prograss

    for x in range(n):
        for y in range(m):
            # if the position is not in item,creat.
            # else print space.
            if not position in item:
                print('■', end='')
            else:
                print(' ', '', end='')
            position[1] += 1
        print()
        position[1] = 1
        position[0] += 1


main()
