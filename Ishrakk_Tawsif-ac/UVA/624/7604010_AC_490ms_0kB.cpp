#include<bits/stdc++.h>
using namespace std;

int n,n_s,track[23],arr[23],ans[23],max_=INT_MIN,min_=0,f_ans[23],til,sum,temp;

void backtrack(int ind){
//cout<<ind<<endl;
    if(ind == n_s){
        sum=0,temp=0;
        for(int i=0; i<n_s; i++){if(arr[i]==1){sum += track[i];}}//cout<<sum<<endl;

        if(sum<=n){
            if(sum>min_){
                min_=max(sum,min_);//cout<<min_<<"---"<<endl;
                    int in=-1;
                    for(int i=0; i<n_s; i++){
                        if(arr[i]==1){
                            f_ans[++in]=track[i];
                        }
                    }
                    til=in;
            }
        }
        return;
    }

    //for(int i=0; i<n_s; i++){
        //if(arr[i] == 0){
            arr[ind]=1;
            //ans[ind]=track[i];
            backtrack(ind+1);
            arr[ind]=0;
            backtrack(ind+1);
        //}
    //}

}

int main(){

    while(scanf("%d", &n) == 1){

        scanf("%d", &n_s);
        for(int i=0; i<n_s; i++) scanf("%d", &track[i]);
        memset(arr,0,sizeof(arr));

                min_=0;
                backtrack(0);//cout<<max_<<endl;

            for(int i=0; i<=til; i++)
                cout<<f_ans[i]<<" ";
                cout<<"sum:"<<min_<<endl;
    }
return 0;
}