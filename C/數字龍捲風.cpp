#include"stdio.h"
int n,way,s,t,data[100][100];
void run(int amount,int way){
	for(int i=0;i<amount;i++){
		if (way==0){t--;}
        if (way==1){s--;}
        if (way==2){t++;}
        if (way==3){s++;}
        printf("%d",data[s][t]);
	}
}
int main(){
	scanf("%d",&n);
	scanf("%d",&way);
	s=t=int(n/2);
	//printf("%d%d",s,t);//check s & t value
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&data[i][j]);	
		}
	}
	printf("%d",data[s][t]);
	for(int i=0;i<(n-1);i++){
		if (way==0){
			run(i+1,0);
        	run(i+1,1);
        	way=2;
        	continue;
		}
		if (way==1){
			run(i+1,1);
        	run(i+1,2);
        	way=3;
        	continue;
		}
		if (way==2){
			run(i+1,2);
        	run(i+1,3);
        	way=0;
        	continue;
		}
		if (way==3){
			run(i+1,3);
        	run(i+1,0);
        	way=1;
        	continue;
		}
	}
	run(n-1,way);
	return 0;
}
