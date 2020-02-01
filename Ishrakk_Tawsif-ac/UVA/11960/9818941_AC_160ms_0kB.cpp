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
#define ll                      unsigned long long int
#define mx                      1000005
#define mod                     1000007
#define intinf                  2100000000
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())


bitset <mx> isprime;
vector <int> prime;

void sieve()
{
    prime.pb(2);

        for(int i=3; i*i<mx; i+=2)
        {
            if(!isprime[i])
            {
                for(int j=i*i; j<mx; j+=i) isprime[j] = 1;
            }
        }
        for(int i=3; i<mx; i+=2)
        {
            if(!isprime[i]) prime.pb(i);
        }
}

int res[mx],answer[mx];

void num_of_div()
{
    res[0]=(-1*intinf);
    for(int n=1; n<=1000000; n++)
    {
        int nn=n,ans=1;
        for(int i=0; prime[i]*prime[i]<=nn; i++)
        {
            if(nn%prime[i] == 0)
            {
                int cnt=0;
                    while(nn%prime[i] == 0)
                    {
                        nn/=prime[i];
                        cnt++;
                    }
                ans *= (cnt+1);
            }
        }
        if(nn!=1) ans *= 2;
        if(ans>=res[n-1]){
            res[n] = ans;
            answer[n] = n;
        }
        else
        {
            res[n] = res[n-1];
            answer[n] = answer[n-1];
        }
    }
}

int main()
{
    sieve();
    num_of_div();
    int tc,n;

        sf(tc);

            loop(tt,1,tc+1)
            {
                sf(n);
                pf("%d\n", answer[n]);
            }
    return 0;
}