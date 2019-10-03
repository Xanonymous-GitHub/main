#include<bits/stdc++.h>
using namespace std;
int man[2000000];
int main(int argc,char* argv[]){
    ios::sync_with_stdio(0),cin.tie(0);
    long m,n,tmp=0;
    cin>>n>>m;
    while (m--){
        cin>>tmp;
        if(man[tmp-1]){
            printf("0u0 ...... ?\n");
            continue;
        }
        while (man[tmp]&&tmp<n)tmp++;
        if(tmp!=n){
            man[tmp]=!man[tmp];
            printf("%ld\n",tmp+1);
        }
        else
        printf("0u0 ...... ?\n");
    }
    return 0;
}