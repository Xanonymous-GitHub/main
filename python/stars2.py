while True:
  n=int(input("n=?"))
  for x in range(0,n,1):
    print(" "*(n-(x+1)),"*"*(x+1))
