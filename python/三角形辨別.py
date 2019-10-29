def judge(data):
    if (data[0]+data[1] <= data[2]):
        return"No"
    elif (data[0]**2+data[1]**2 < data[2]**2):
        return"Obtuse"
    elif (data[0]**2+data[1]**2 == data[2]**2):
        return"Right"
    elif (data[0]**2+data[1]**2 > data[2]**2):
        return"Acute"


while True:
    try:
        line = input()
    except:
        break
    data = list(map(int, line.split()))
    data.sort()
    print(data[0], data[1], data[2])
    print(judge(data))
