#include<bits/stdc++.h>
using namespace std;
int main(int argc,char* argv[]){
    ios::sync_with_stdio(0), cin.tie(0);
    long m,n;

    //get user data
    cin>>n>>m;
    long kill[m];
    for(long i=0;i<m;i++)cin>>kill[i];

    //init a array from 1 to n
    long man[n];
    for(long i=0;i<n;i++)man[i]=i+1;

    //kill people
    for (long i = 0; i < sizeof(kill)/4; i++)
    {
        //kill[i] is the current person to be killed now.

        //find if kill[i] is still alive or second last.
        long pos=0;
        bool in=false;
        while (pos<sizeof(man)/4)
        {
            if(kill[i]==man[pos]){
                in=!in;
                break;
            }
            pos++;
        }
        if (in&&(pos<sizeof(man)/4-1))
        {
            cout<<man[pos+1]<<endl;
            man.erase(man.begin()+pos+1);
        }
        else{
            cout<<"0u0 ...... ?"<<endl;
        }
        
        
        //if true,remove its next element and print it.
        //else,print "0u0 ...... ?" 
    }
    return 0;
}