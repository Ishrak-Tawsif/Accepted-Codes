#include<bits/stdc++.h>
using namespace std;

char alpha[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int arr[31],ans[31],cnt,n,k;

void backtrack(int ind){
    if(cnt == k) return;
    if(ind == n){
        for(int i=0; i<n; i++) printf("%c", alpha[ans[i]]);
        printf("\n");
        cnt++;
    }

    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            ans[ind]=i;
            arr[i]=1;
            backtrack(ind+1);
            arr[i]=0;
        }
    }
}

int main(){
//..
    int tc;
        scanf("%d", &tc);
            for(int tt=1; tt<=tc; tt++){

                scanf("%d %d", &n, &k);
                        cnt=0;
                        printf("Case %d:\n", tt);
                        backtrack(0);
            }
return 0;
}