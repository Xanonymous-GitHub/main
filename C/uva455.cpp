#include<bits/stdc++.h>
using namespace std;
int fuck(int n,string data){
    for (int i = 1; i < n+1; i++)
    {
        if (!(n%i))
        {
            string tmp;
            for (int j = 0; j < i; j++)
            tmp+=data[j];
            for (int j = i; j < n; j++)
            {
                if (data[j]!=tmp[j%i])break;
                if (j==n-1)return i;
            }
        }
    }
    return n;
}
int main(int argc,char* argv[]){
    ios::sync_with_stdio(0), cin.tie(0);
    int n=0;
    string data;
    cin>>n>>data;
    cout<<fuck(n,data)<<endl;
    return 0;
}