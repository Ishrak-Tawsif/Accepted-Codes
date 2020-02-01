#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,x;

        while(cin>>n >>x){

            int in,equal=0,right=0,left=0,ans=0;
            for(int i=1; i<=n; i++){
                cin>> in;
                    if(in == x) equal++;
                    else if(in>x) right++;
                    else left++;
            }

                if(equal == 0){
                    equal = 1; ans=1;
                }
                if ((left+equal)<right){
                    ans += right - (equal+left);
                    if(((n+ans)%2) == 1) ans--;
                }else if((right+equal-1)<left+1){
                    ans = left - (equal+right)+2;
                    if(((n+ans)%2) == 0) ans--;
                }
                    cout << ans << endl;
        }
   return 0;
}