#include<bits/stdc++.h>
using namespace std;

#define ll long long int


ll pp[111];
ll ans[111];

ll calc(ll n,ll k,ll mod)
{
    ll temp=1;
    n%=mod;
        while(k){
            if(k&1) temp=(temp*n)%mod;
            n=(n*n)%mod;
            k>>=1;
            temp%=mod;
        }
//cout << k << endl;
    temp%=mod;
return temp;
}
int main()
{
    ll a,k,n,c;
    int testcase=1;
    while(scanf("%lld %lld %lld",&n,&k,&a)==3&&n&&k&&a){

        memset(pp,0,sizeof(pp));
        memset(ans,0,sizeof(ans));

        scanf("%lld",&c);

            for(ll i=0;i<c;i++) scanf("%lld",&pp[i]);

            printf("Case %d:\n",testcase++);

            int tot=0;

                for(int i=0;i<c;i++)
                    ans[tot++]=((a%pp[i])*calc(k,n,pp[i]))%pp[i];
                    for(int i=0;i<tot;i++){
                        if(i) printf(" ");
                        printf("%lld",ans[i]);
                    }
        printf("\n");
    }

   return 0;
}
