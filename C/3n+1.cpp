#include<stdio.h>
int main(){
	int n2,count=0;
	scanf("%d",&n2);
	long long n=n2;
	while (n>1){
		if(n%2)n=3*n+1;
		else n/=2;
		printf("%d\n",n);
		count++;
	}
	printf("%d\n",count);
	return 0;
}
