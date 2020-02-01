#include<bits/stdc++.h>
using namespace std;

#define ll long long


ll gcd (ll a, ll b){

    if(a == 0) return b;
    else return gcd(b%a,a);
}

int main(){

    int testcase;
    ll x1,x2,y1,y2,dis1,dis2;

        scanf("%d", &testcase);

            for(int t=1; t<=testcase; t++){
                scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
                dis1 = abs(x2-x1); dis2 = abs(y2-y1);

                    printf("Case %d: %lld\n", t, gcd(dis1, dis2)+1);
            }
return 0;
}