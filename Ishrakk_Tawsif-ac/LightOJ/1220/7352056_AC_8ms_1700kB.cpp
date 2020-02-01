#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll ipow(ll base, ll pow){

    ll res=1;

        while (pow--) res *= base;
    return res;
}

int main(){

    ll x,temp,ans;
    int testcase;
    scanf("%d", &testcase);

     for(int tt=1; tt<=testcase; tt++){
        cin>> x;
        ans=-1;

        if(x<0){

            x=x*-1;

                for(int i=2; i<=sqrt(x); i++){
                    for(int j=3; ; j+=2){
                        temp=ipow(i,j);
                        if(temp == x) {ans=j; break;}
                        else if(temp>x) break;
                    }
                    if(ans!=-1) break;
                }
        }
        else{
            for(int i=2; i<=sqrt(x); i++){
                for(int j=1; ; j++){
                    temp=ipow(i,j);
                        if(temp == x) {ans=j; break;}
                        else if(temp>x) break;
                }
                if(ans!=-1) break;
            }
        }
        if(ans==-1) printf("Case %d: 1\n",tt);
        else printf("Case %d: %lld\n", tt,ans);
     }
return 0;
}