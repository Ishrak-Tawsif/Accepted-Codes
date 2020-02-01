#include<bits/stdc++.h>
using namespace std;


int main(){

    int n,k;

        while(cin>>n >>k){

            int arr[n+5],max_;
            for(int i=0; i<n; i++) cin>> arr[i];

                if(k>=n) cout << arr[n-1] << endl;
                else{
                            int max_ = arr[n-1];
                            for(int i=0; i<=n-k; i++){
                                max_ = max(max_, arr[i]+arr[((n-k)*2)-i-1]);
                            }
                            cout << max_ << endl;
                        }
                }

return 0;
}
