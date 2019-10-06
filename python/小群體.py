def process (n,data):
  self=list()
  for x in range(n):self.append(x)
  result=0
  group=set()
  first=0
  while len(group)!=n:
    if first in group:first+=1
    else:
      k=first
      while data[k]!=first:
        group.add(k)
        k=data[k]
      group.add(k)
      first+=1
      result+=1
  return result
while True:
  try:line=input()
  except:break;
  n=int(line)
  data=list(map(int,input().split()))
  print(process(n,data))
