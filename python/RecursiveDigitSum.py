data=input().split()
result = int(data[0]*int(data[1])) % 9
print(result if result else 9)