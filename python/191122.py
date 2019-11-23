from os import getcwd


def rdfile():
    data = list()
    # 顯示這個程式碼檔案是在哪裡被執行
    print(getcwd())
    with open("pm25.txt", 'r') as fd:
        for line in fd:
            try:
                data.append(float(line.replace('\n', '')))
            except:
                pass
    print('Max =', max(data))
    print('Min =', min(data))
    print('Avg =', (sum(data)/len(data)))
    data_bigger_than_70 = int()
    for x in range(len(data)):
        if data[x] > 70:
            data_bigger_than_70 += 1
    print('The amount of data which is bigger than 70 :', data_bigger_than_70)


def main():
    rdfile()


if __name__ == '__main__':
    main()
