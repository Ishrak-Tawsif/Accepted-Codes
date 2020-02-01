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
#define mx                      100005
#define mod                     100000007


int dr8[]={-1,-1,0,1,1,1,0,-1};
int dc8[]={0,1,1,1,0,-1,-1,-1};

int tr[100005];

int main()
{//WRITE("in.txt");
    ll n;
//for(int i=1; i<=100000; i++)pf("%d\n",i);exit(0);
    while(scanf("%lld", &n) && n)
    {
        ll sum = 0,temp = n,tsum,ans;
        while(temp != 0)
        {
            ll digit = temp%10;
            sum += digit;
            temp/=10;
        }//cout<<sum<<endl;

        for(ll i=11; ; i++)
        {
            tsum=0;
            temp = n*i;
            while(temp != 0)
            {
                ll digit = temp%10;
                tsum += digit;
                temp/=10;
            }
            if(tsum == sum){ans=i;break;}
        }
        cout<<ans<<endl;
    }
    return 0;
}