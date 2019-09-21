#include<iostream>
#include<cstdio>
using namespace std; 
int main() {     
  int t[4],in[4],ma[4],n,a,b,tb[4],inb[4];
  //while (cin >> t[0] >> t[1] >> t[2] >> t[3]){
  while (scanf("%d %d %d %d",&t[0],&t[1],&t[2],&t[3])==4){  //改成scanf printf比較快
    //cin >>n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      a=b=0;
      for(int j=0;j<4;j++){
        tb[j]=0;//用於B的輸出，目標值該位置是否比較過，tb[i]=1，表示已經用過
        inb[j]=0;//用於B的輸出，輸入值該位置是否比較過，inb[i]=1，表示已經用過
        //cin >> in[j];
        scanf("%d",&in[j]);
        if (t[j]==in[j]) {
          ma[j]=1;
          a++;
        }else{
          ma[j]=0;      
        }
      }
      for(int j=0;j<4;j++){
        for(int k=0;k<4;k++){
            if ((j!=k)&&(!ma[j])&&(!ma[k])&&(!tb[j])&&(!inb[k])){//沒有用過的A與B位置，可以比較產生B
              if (t[j]==in[k]) {
                b++;
                tb[j]=1;
                inb[k]=1;
                break;
              }
            }
        }
      }            
      printf("%dA%dB\n",a,b);      
    }
  }
  return 0;
}