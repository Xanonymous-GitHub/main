#include<cstdio>
#include<iostream>
using namespace std;
int result[10005][2];
int ca(int data_init[],int psd_init[],int now){
    //A
    int data[4],psd[4];
    for (int i = 0; i < 4; i++)
    {
        data[i]=data_init[i];
        psd[i]=psd_init[i];
    }
    int a=0,b=0;
    for (int i = 0; i < 4; i++)
    {
        if(data[i]==psd[i]){
            data[i]=-1;
            psd[i]=-1;
            a++;
        }
    }
    //B
    for (int i = 0; i < 4; i++)
    {
        bool tmp=false;
        int pos=0;
        while (pos<4)
        {
            if(data[i]==psd[pos++]){
                tmp=true;
                break;
            }
        }
        if((data[i]!=-1)&&(data[i]!=psd[i])&&(tmp)){
            b++;
        }
    }
    result[now][0]=a;
    result[now][1]=b;
    return 0;
}
int main(int argc,char* argv[]){
    int psd[4],n=0,dat[4];
    while (scanf("%d%d%d%d",&psd[0],&psd[1],&psd[2],&psd[3])==4)
    {
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d%d%d",&dat[0],&dat[1],&dat[2],&dat[3]);
            ca(dat,psd,i);
        }
        for (int i = 0; i < n; i++)
        {
            printf("%dA%dB\n",result[i][0],result[i][1]);
        }
    }
    return 0;
}
//1 1 1 5
//1 5 2 3 
//more b ??