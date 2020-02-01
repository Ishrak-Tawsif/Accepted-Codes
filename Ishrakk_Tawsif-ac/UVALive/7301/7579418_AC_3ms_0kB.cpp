#include<bits/stdc++.h>
using namespace std;


int main(){

    int prob,c_du,testcase;
        scanf("%d", &testcase);
            for(int tt=1; tt<=testcase; tt++){
                scanf("%d %d", &prob, &c_du);
                    int arr[prob+1];
                        for(int i=0; i<prob; i++) scanf("%d", &arr[i]);
                        sort(arr, arr+prob);
                            int sum=0,time=0,last,p=0;
                                for(int i=0; i<prob; i++){
                                    if(sum+arr[i]<=c_du){
                                        sum+=arr[i];
                                        time += sum;///cout<<sum<<" "<<time<<endl;
                                        p++;
                                    }
                                }
                   printf("Case %d: %d %d %d\n",tt,p,sum,time);
            }
return 0;
}