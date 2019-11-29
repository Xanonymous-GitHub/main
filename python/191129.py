with open('/home/xanonymous/vscode/main/python/example.txt', 'r') as f:
    data = f.read().split('\n')
count_list = list()
for x in set(data):
    count_list.append([data.count(x), x])
count_list.sort(reverse=True)
for x in count_list[:5]:
    print(x[1])