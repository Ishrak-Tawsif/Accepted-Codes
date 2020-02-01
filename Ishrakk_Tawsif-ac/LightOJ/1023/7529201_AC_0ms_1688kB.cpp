#include<bits/stdc++.h>
using namespace std;

string alp="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int n,k,tc,arr[35],al[35],cnt=0;

int backtrack(int in){

    if(cnt == k) return 0;
    if(in==n){
        for(int j=0; j<n; j++){
            printf("%c", alp[al[j]]);
        }
        printf("\n");
        cnt++;
    }
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            arr[i]=1;
            al[in]=i;
            backtrack(in+1);
            arr[i]=0;
        }
    }
}

int main(){
    scanf("%d", &tc);
    for(int i=1; i<=tc; i++){
        scanf("%d %d", &n, &k);
        printf("Case %d:\n",i);
        cnt=0;
        backtrack(0);
    }

return 0;
}