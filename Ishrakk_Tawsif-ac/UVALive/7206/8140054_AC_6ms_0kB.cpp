#include<bits/stdc++.h>
using namespace std;

long long int chal[]= {10000, 1000, 100, 10, 1};

int main()
{
    long long int n,cnt,temp,m,arr[23];

        while(scanf("%lld %lld", &n,&m) == 2)
        {
            long long int ans=0;
            while(m--){
            long long int sum=0,b;

                scanf("%lld", &b);
                //cout<<b<<endl;
                cnt=0;
                for(int i=0; i<n; i++){
                    scanf("%lld", &arr[i]);
                    if(i!=0) sum+=(long long int)arr[i];
                }
                //temp=abs(sum-arr[0]);
                    //if(temp<b){
                        int i=0;//cout<<sum<<endl;
                            while(i<5){//cout<<i<<endl;
                                        if(chal[i]<=(b-sum)){
                                        cnt=chal[i];
                                        //i++; //cout<<chal[i]+sum<<" "<<b<<endl;
                                        break;
                                    }i++;
                            }

                    if((b-sum)<arr[0]) arr[0]=0;
                ans+= (long long int)(cnt-arr[0]);

            }
            cout<<ans<<endl;
        }
    return 0;
}