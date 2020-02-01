#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d:\n",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     2e9
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

ll track[2000005],ar[2005],ar2[2005],n;

int main()
{//WRITE("in.txt");

    ll a,b,c,fl;

    while(~scanf("%lld %lld %lld",&a,&b,&c))
    {
        fl=1;
        ll sum = a+b+c;//cout<<sum<<endl;
        if(((a+b)<c) || ((b+c)<a) || ((c+a)<b) || (sum%2)) fl=0;

        if(!fl)pf("Impossible\n");

        else
        {
            sum/=2;
            ll temp1 = sum - a;
            ll temp2 = sum - b;
            ll tempc = sum - c;

            if(temp1<0 || temp2<0 || tempc<0)pf("Impossible\n");
            else pf("%lld %lld %lld\n",tempc,temp1,temp2);
        }
    }

    return 0;
}