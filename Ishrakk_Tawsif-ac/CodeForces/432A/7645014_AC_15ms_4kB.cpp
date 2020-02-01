#include<bits/stdc++.h>
using namespace std;


int main(){

    int n,k,arr[2003],ans;

        while(cin>> n>> k){

            ans=0;
            for(int i=0; i<n; i++) scanf("%d", &arr[i]);

                sort(arr, arr+n);

                    for(int i=2; i<n; i+=3){

                        if(arr[i]+k<=5) ans++;
                    }
                 cout<<ans<<endl;
        }
return 0;
}