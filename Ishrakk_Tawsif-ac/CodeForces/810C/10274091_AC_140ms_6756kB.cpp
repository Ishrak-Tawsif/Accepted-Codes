#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      300005
#define mod                     1000000007


int dr8[]={-1,-1,0,1,1,1,0,-1};
int dc8[]={0,1,1,1,0,-1,-1,-1};


ll powr[mx],arr[mx];

void gen()
{
    powr[0]=1;
    for(int i=1;i<mx; i++)
    {
        powr[i] = ((powr[i-1]%mod)*2)%mod;
    }
}


int main()
{
    gen();

    int n;

        sf(n);

            for(int i=0; i<n; i++)scanf("%lld",&arr[i]);

            sort(arr,arr+n);

            ll ans=0,tt;
            /*for(int i=n-1,k=2; i>=0; i--,k++)
            {//cout<<arr[i]<<"....\n";
                tt=k;
                for(int j=0; j<i; j++)
                {//cout<<" " <<arr[j]<<" ";
                    ll temp = (powr[n-tt++])%mod;
                    ans = ((ans%mod) + (temp%mod * (arr[i]-arr[j])%mod))%mod;//cout<<temp<<" "<<arr[i]-arr[j]<<endl;
                }//cout<<ans<<endl;
                //system("pause");
            }*/

            for(int i=0;i<n;i++)
            {
                ll temp = (((powr[i])%mod-(powr[n-i-1])%mod)%mod * (arr[i]%mod))%mod;//cout<<powr[i]-powr[n-i-1]<<endl;
                ans = (ans%mod+temp%mod)%mod;
            }
            cout<<(ans)%mod<<endl;
}