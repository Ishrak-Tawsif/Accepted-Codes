#include<bits/stdc++.h>
using namespace std;

int input[7],arr[7],value[5],fl;

void backtrack(int ind,int val){

    if(ind==5){
        if(val==23) {fl=1; return;}
    }

        for(int i=0; i<5; i++){
            if(arr[i]==0)
            {
                arr[i]=1;
                backtrack(ind+1,val+input[i]);
                backtrack(ind+1,val-input[i]);
                backtrack(ind+1,val*input[i]);
                arr[i]=0;
            }
        }
}

int main(){

    while(scanf("%d %d %d %d %d",&input[0],&input[1],&input[2],&input[3],&input[4])==5)
    {
        fl=0;
        if(input[0]==0&&input[1]==0&&input[2]==0&&input[3]==0&&input[4]==0) break;
        for(int ii=0; ii<5; ii++)
            {
                arr[ii]=1;
                backtrack(1,input[ii]);
                arr[ii]=0;
                if(fl==1) {cout<<"Possible"<<endl;break;}
            }
            if(fl==0) cout<<"Impossible"<<endl;

    }
return 0;
}