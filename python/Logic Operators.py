def and_(a,b,c):
  result=list()
  if (a and b)==c:result.append("AND")
  if(a or b)==c:result.append("OR")
  if(a != b)==c:result.append("XOR")
  return result
def print_(rel):
  if len(rel)==0:
    print("IMPOSSIBLE")
    return
  for x in range(len(rel)):print(rel[x])
  return
keyin=list(map(int,input().split()))
print_(and_(bool(keyin[0]),bool(keyin[1]),bool(keyin[2])))
