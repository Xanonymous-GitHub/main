# Python made by Xanonymous @ 191203, all rights reserved.


class Message():

    def __init__(self, mix):
        self.__mix = mix
        self.__time, self.__text = self.__separate(self.__mix)

    def __separate(self, data):
        __num = list(map(str, list(range(10))))
        __i = 0
        while (data[__i] in __num):
            __i += 1
        return [self.__mix[:__i], self.__mix[__i+1:]]

    def __str__(self):
        return '%s' % self.__text

    __repr__ = __str__

    def is_read(self, time):
        return True if int(self.__time) <= time else False


def main():
    try:
        n = int(input())
    except:
        return False
    data = list()
    for x in range(n):
        data.append(Message(input()))
    m = int(input())
    time = list()
    for x in range(m):
        time.append(int(input()))
    for x in range(m):
        read = False
        while ((len(data)) and (data[0].is_read(time[x]))):
            read = True
            print(data[0])
            data.pop(0)
        if(read and (len(data))):
            print('-')


if __name__ == '__main__':
    while main():
        pass
