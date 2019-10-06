#include<stdio.h>
int main(){
	for (int x=1;;x++){
		int n=x*x;
		if(n<1000)continue;
		if(n>9999)break;
		int hi=n/100;//77
		int lo=n%100;//44
		if(hi/10==hi%10&&lo/10==lo%10)printf("%d",n);
		//hi/10=7;hi%10=7
	}
	return 0;
}
