#include<bits/stdc++.h>
using namespace std;
int qs(int* data){
    if (!data)return;
    int lendata=sizeof(data)/sizeof(int);
    int SFR=lendata-1,BFL=0;
    while(BFL!=SFR){
        while(SFR>0 && data[SFR]>=data[0])SFR-=1;
        while(BFL!=SFR && BFL<lendata-1 and data[BFL]<=data[0])BFL+=1;
        if(BFL!=SFR){
            data[SFR]^=data[BFL];
            data[BFL]^=data[SFR];
            data[SFR]^=data[BFL];
        }
    }
    data[0]^=data[BFL];
    data[BFL]^=data[0];
    data[0]^=data[BFL];

    int left[BFL],right[lendata-BFL-1];
    for(int i=0;i<BFL;i++)left[i]=data[i];
    for(int i=0;i<lendata-BFL-1;i++)right[i]=data[i+BFL+1];
    return qs(left)+[data[BFL]]+qs(right);
}
int main(int argc,char* argv[]){
    ios::sync_with_stdio(0),cin.tie(0);
    int n=0;
    cin>>n;
    int data[n];
    for (int i = 0; i < n; i++)cin>>data[i];
    cout<<qs(data)<<endl;
    return 0;
}