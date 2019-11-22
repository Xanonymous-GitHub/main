data = list()
with open("pm25.txt", 'r') as fd:
    for line in fd:
        try:
            data.append(float(line.replace('\n', '')))
        except:
            pass
print('Max =', max(data))
print('Avg =', (sum(data)/len(data)))