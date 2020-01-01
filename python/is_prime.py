n=int(input())
for x in range(2,n):
	m=1
	for y in range(2,x):
		if not(x%y):
			m=not m
			break
	if (m):print(x)