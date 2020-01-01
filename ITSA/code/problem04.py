import math


def distance(a, b, A, B):
    return (((A-a)**2)+((B-b)**2))**(0.5)


def isthisisaaqure(data, n):
    distance_list = list()
    distance_list.append(distance(data[0], data[1], data[2], data[3]))
    distance_list.append(distance(data[0], data[1], data[4], data[5]))
    distance_list.append(distance(data[0], data[1], data[6], data[7]))
    distance_list.sort()
    if not(0 in distance_list):
        if len(set(distance_list)) > 1:
            if distance_list[0] == distance_list[1]:
                return [1, (n*n)*(int(min(list(set(distance_list)))**2))]
    return [0, -1]


n = int(input())
white = list(map(int, input().split()))
whilt_is_squ = [0, -1]
whilt_is_squ = isthisisaaqure(white, n)
if(whilt_is_squ[0]):
    print('Yes', whilt_is_squ[1])
else:
    print('No')
black = list(map(int, input().split()))
black_is_squ = [0, -1]
black_is_squ = isthisisaaqure(black, n)
if(black_is_squ[0]):
    print('Yes', black_is_squ[1])
else:
    print('No')

if(whilt_is_squ[1] > black_is_squ[1]):
    print('A')
elif(whilt_is_squ[1] < black_is_squ[1]):
    print('B')
else:
    print('Peace')
