data = input()
n = int(input())
a_in_data = 0
lendata = len(data)
for x in data:
    if x == 'a':
        a_in_data += 1
a_in_data *= n//lendata
for x in range(n % lendata):
    if data[x] == 'a':
        a_in_data += 1
print(a_in_data)