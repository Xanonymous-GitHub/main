def prime(n):
	c=2
	while(c<n):
		if not(n%c):return ''
		c+=1
	return str(n)+'\n'
def main():
	n=int(input())
	for x in range(2,n):
		print(prime(x),end='')
if __name__=='__main__':
	main()
