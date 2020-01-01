#include<stdio.h>
int recu(long long int a,long long int b){
    if(a==0)return b;
    if(b==0)return a;
    return recu(b,(a-b*(a/b)));
}
int main(int argc,char* argv[]){
    long long int a,b;
    while (scanf("%lld%lld",&a,&b)==2)
    {
        if(a<b){
            a^=b;
            b^=a;
            a^=b;
        }
        printf("%lld\n",recu(a,b));
    }
    
    return 0;
}