usr_input=input()
n=int(input())
data=list(usr_input*n)
result=int()
for x in range(len(data)):
    if data[x] == 'a' and x<n:result+=1
print(result)