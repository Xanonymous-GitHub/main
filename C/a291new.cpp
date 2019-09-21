#include<cstdio>
int main(int argc,char*argv[]){
    int psd[4],n;
    while (scanf("%d%d%d%d",&psd[0],&psd[1],&psd[2],&psd[3])==4)
    {
        scanf("%d",&n);
        int result[10005][2];
        int count=1;
        for (int i = 0; i < n; i++)
        {
            int used[4]={0},tmp[4],a=0,b=0,binused[10]={0};
            scanf("%d%d%d%d",&tmp[0],&tmp[1],&tmp[2],&tmp[3]);
            for (int j = 0; j < 4; j++)
            {
                if(tmp[j]==psd[j]){
                    a++;
                    used[j]=1;
                }
            }
            for (int j = 0; j < 4; j++)
            {
                if (!used[j])
                {
                    for (int k = 0; k < 4; k++)
                    {
                        if ((!used[k])&&(tmp[j]==psd[k])&&(!binused[tmp[j]-1])){
                            binused[tmp[j]-1]=1;
                            b++;
                            break;
                        }
                    }
                }
            }
            result[i][0]=a;
            result[i][1]=b;
        }
        
        for (int i = 0; i < n; i++){
            if ((result[i][0]==0)&&(result[i][1]==1)&&(count==2))
            {
                count++;
                printf("%d%d%d%d ",psd[0],psd[1],psd[2],psd[3]);
            }
            printf("%dA%dB\n",result[i][0],result[i][1]);
        }
        
    }
    return 0;
}