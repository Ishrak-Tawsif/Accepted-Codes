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
#define inf                     1e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

const int lim = 1151;

bitset <lim> isprime;
vector <int> prime;
int n,k,dp[193][1200][17];

void sieve()
{
    isprime[0] = isprime[1] = 1;

    for(int i=3; i*i<lim; i+=2)
    {
        for(int j=i*i; j<lim; j+=i) isprime[j] = 1;
    }

    prime.pb(2);
    for(int i=3; i<lim; i+=2)
        if(!isprime[i]) prime.pb(i);
    //cout<<prime.size()<<endl;
}

int call(int pos,int tot,int totkk)
{//cout<<pos<<" "<<tot<<" "<<totkk<<endl;
    if(totkk == k) {if(tot == n)return 1; else return 0;}
    if(tot == n) return 0;
    if(pos>=prime.size()) return 0;
    if(prime[pos]>n) return 0;

    if(dp[pos][tot][totkk] != -1) return dp[pos][tot][totkk];

    int ans1 = 0,ans2 = 0;

    //for(int i=pos; i<prime.size(); i++)
    //{
        if(totkk<k && tot+prime[pos]<=n) ans1 = call(pos+1,tot+prime[pos],totkk+1);
        ans2 = call(pos+1,tot,totkk);
        //else break;
    //}
//cout<<ans1<<" "<<ans2<<endl;
    return dp[pos][tot][totkk] = (ans1+ans2);
}

int main()
{//WRITE("in.txt");
    sieve();
    mem(dp,-1);
    //n=24,k=3;
    //cout<<call(0,0,0)<<endl;;
    while(scanf("%d %d", &n,&k))
    {
        if(!n && !k) break;
        mem(dp,-1);
        pf("%d\n",call(0,0,0));
    }
}