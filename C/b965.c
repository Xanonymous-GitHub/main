#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define X 10
int data[X][X],tmpdata[X][X];
int rotate(int r,int c){
    //r=3,c=2
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            tmpdata[c-j-1][i]=data[i][j];
        }
    }
    //copy the data
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            data[i][j]=tmpdata[i][j];
        }
    }
    return 0;
}
int flip(int r,int c){
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            tmpdata[r-i-1][j]=data[i][j];
        }
    }
    //copy the data
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            data[i][j]=tmpdata[i][j];
        }
    }
    return 0;
}
int main(int argc,char *argv[]){
    int r,c,m,opt[X];
    while (scanf("%d%d%d",&r,&c,&m)==3)
    {
        //get user data
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                scanf("%d",&data[i][j]);
            }
        }
        //get user operations
        for (int i = 0; i < m; i++) scanf("%d",&opt[i]);
        //judge the operations
        for (int i = m-1; i >=0; i--)
        {
            if (opt[i]){
                flip(r,c);
            }
            else {
                rotate(r,c);
                int tmp=r;
                r=c;
                c=tmp;
            }
        }
        //print result
        printf("%d %d\n",r,c);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c-1; j++)
            {
                printf("%d ",data[i][j]);
            }
            printf("%d\n",data[i][c-1]);
        }
    }
    return 0;
}