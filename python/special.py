class MyData():
    def __init__(self, data, key):
        self.__data = data
        self.__key = key

    def __sort__key(self, e):
        return e[self.__key]

    def get_sorted(self, key, _reverse=False):
        return self.__data.sort(key=self.__sort__key, reverse=_reverse)

    def __str__(self):
        return '%s' % ','.join(map(str, self.__data))


def main():
    data = list()
    key = int(input('KEY= '))
    for x in range(int(input('N= '))):
        data.append(list(map(int, input().split())))
    my_data = MyData(data, key)
    my_data.get_sorted(key)
    print('Sorted By Key at %s:' % key, my_data)


if __name__ == "__main__":
    main()
