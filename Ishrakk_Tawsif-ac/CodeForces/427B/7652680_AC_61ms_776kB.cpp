#include<bits/stdc++.h>
using namespace std;


int main(){

    long int n,t,c;

        while(scanf("%d %d %d", &n, &t, &c)==3){

            int arr[n+1];
                for(int i=0; i<n; i++) scanf("%d", &arr[i]);

                    int cnt=0,ans=0;
                    for(int i=0; i<n; i++){
                        if(arr[i]<=t)cnt++;
                        else{
                            if(cnt>=c)ans += (cnt-c)+1;
                            cnt=0;
                        }
                    }//cout<<ans<<endl;

                    if(cnt!=0 && cnt>=c) ans += ((cnt-c)+1);
                    cout<<ans<<endl;
        }
return 0;
}