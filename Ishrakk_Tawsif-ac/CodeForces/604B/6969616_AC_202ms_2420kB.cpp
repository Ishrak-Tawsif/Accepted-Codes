#include<bits/stdc++.h>
using namespace std;


int main(){

    int n,k;

        while(cin>>n >>k){

            int arr[n+5],max_;
            for(int i=0; i<n; i++) cin>> arr[i];

                if(k>=n) cout << arr[n-1] << endl;
                else{
                            int max_ = arr[n-1],len = ((n-k)*2)-1;
                            for(int i=0,j=len; i<=n-k; i++,j--){
                                max_ = max(max_, arr[i]+arr[j]);//cout << j << endl;
                            }
                            cout << max_ << endl;
                        }
                }

return 0;
}
