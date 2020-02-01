#include<bits/stdc++.h>
using namespace std;

int k,arr[15],num[15],ans[15];

void backtrack(int ind, int pos){
//cout<<ind<<endl;
    if(ind == 6){
        for(int i=0; i<5; i++) cout <<ans[i]<<" ";
        cout<<ans[5]<<endl;
     return;
    }

    for(int i=pos; i<k; i++){

        if(arr[i]==0){
            arr[i]=1;
            ans[ind]=num[i];
            backtrack(ind+1,i+1);
            arr[i]=0;
        }
    }return;
}

int main(){

    int tt=0;
        while(scanf("%d", &k) == 1 && k){
            if(tt!=0) printf("\n");
            tt++;
            for(int i=0; i<k; i++) scanf("%d", &num[i]);
            backtrack(0,0);
        }
return 0;
}