//e331 init @ Xanonymous 190910 --master
#include <stdio.h>
#include <stdlib.h>
#define G 1005
long long int sortarr(long long int *data,int n){
    //only bubble sort XD
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (data[i]<data[j])//from small to big
            {
                int tmp=data[i];
                data[i]=data[j];
                data[j]=tmp;
            }
        }
    }
    return 0;
}
int main(int argc,char* argv[]){
    int t,n,k;
    long long int l,u,x[G],y[G];
    while (scanf("%d",&t)==1)
    {
        //get user data
        scanf("%d%lld%lld%d",&n,&l,&u,&k);
        for (int i = 0; i < n; i++) scanf("%lld",&x[i]);
        for (int i = 0; i < n; i++) scanf("%lld",&y[i]);
        //sort x and y
        sortarr(x,n);
        //printf("%d",sizeof(x));
        //sortarr(y);
        
        //test the x array
        for (int i = 0; i < n; i++)
        {
            printf("%lld ",x[i]);
        }
        
        //match max with min
        //ptint the result
    }
    return 0; 
}