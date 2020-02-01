#include<bits/stdc++.h>
using namespace std;

int main(){

    long long int n;

        while(cin>> n){

             long long int b[n+5],max_,ans=0;  //cout << ans;

                for(int i=0; i<n; i++) cin>> b[i];

                sort(b, b+n);

                max_ = b[n-1] - b[0];

                        long long int cnt=0,temp=0;
                        //cout << ++i << " " << --j;
                            for(int i=0; i<n; i++){
                                if(b[i] == b[0]) cnt++;
                                if(b[n-1] == b[i]) temp++;
                            }
                            ans = temp*cnt;
                            if(cnt == n) ans = n*(n-1)/2;


                        cout << max_ << " " << ans << endl;
                    }
return 0;
}