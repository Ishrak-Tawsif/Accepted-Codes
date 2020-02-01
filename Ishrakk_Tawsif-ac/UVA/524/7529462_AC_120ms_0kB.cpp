#include<bits/stdc++.h>
using namespace std;

string alp="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int n,k,tc,arr[35],al[35],cnt=0;
bitset<101>isprime;

void sieve(){

    isprime[0]=isprime[1]=1;

        for(int i=4; i<101; i+=2) isprime[i]=1;

            for(int i=3; i<101; i+=2){
                if(!isprime[i]){
                        for(int j=i*i; j<101; j+=i) isprime[j]=1;
                }
            }
}

void backtrack(int in){

    //if(cnt == k) return 0;
    if(in==n+1){
        int fl=0;
        /*for(int j=2; j<=n-1; j++){
            int t1=al[j]+al[j+1];
            int t2=al[j]+al[j-1];
                if(isprime[t1]==1 || isprime[t2]==1){fl=1; break;}
        }*/
        if(isprime[al[1]+al[n]]==1) fl=1;
        if(fl==0){printf("%d", al[1]);for(int j=2; j<=n; j++)printf(" %d", al[j]);}
        if(fl==0)printf("\n");
        return;
    }
    for(int i=2; i<=n; i++){
        if(arr[i]==0 && !isprime[i+al[in-1]]){
            arr[i]=1;
            al[in]=i;
            backtrack(in+1);
            arr[i]=0;
        }
    }
}

int main(){
    sieve();
    //for(int i=1; i<=tc; i++){
    int i=0;
    while(scanf("%d", &n)==1){
        if(i>0)printf("\n");
        printf("Case %d:\n",++i);
        al[1]=1;
        backtrack(2);
    }
return 0;
}