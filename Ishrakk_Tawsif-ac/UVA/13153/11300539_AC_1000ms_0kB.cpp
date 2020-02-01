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
#define inf                     1e9
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      1000005
#define mod                     1000000007

bitset <mx> isprime;
vector <int> prime;
int ar[100005],par[mx],vis[mx];
bool mark[mx];
vector <int> graph[mx];

void sieve()
{
    isprime[0] = isprime[1] = 1;
    prime.pb(2);

    for(int i=3; i*i<mx; i+=2)
    {
        if(!isprime[i])
        {
            for(int j=i*i; j<mx; j+=i) isprime[j]=1;
        }
    }

    for(int i=3; i<mx; i+=2) if(!isprime[i]) prime.pb(i);
    //out(prime.size());
}

void dfs(int sr)
{
    vis[sr] = 1;
//cout<<sr<<"..//"<<endl;
//cout<<graph[sr].size()<<endl;
    for(int i=0; i<graph[sr].size(); i++)
    {
        int vv = graph[sr][i];
//cout<<vv<<endl;
        if(!vis[vv])
            dfs(vv);
    }
}

int main()
{
    sieve();
    int tc,n;

    scanf("%d", &tc);

    for(int tt=1; tt<=tc; tt++)
    {

        scanf("%d", &n);

        for(int i=0; i<mx; i++)graph[i].clear(),vis[i]=0,par[i]=-1,mark[i]=0;

        for(int i=0; i<n; i++) scanf("%d", &ar[i]),mark[ar[i]] = 1;


        for(int i=0; i<prime.size(); i++) par[prime[i]] = prime[i];

        for(int i=0; i<prime.size(); i++)
        {
            int curp = prime[i];
            for(int j=curp+curp; j<=mx; j+=curp)
            {
                if(mark[j])
                {
                    if(par[curp] != par[j])
                    {
                        if(par[curp] != -1 && par[j] != -1)
                        {//cout<<par[curp]<<" .. "<<par[j]<<endl;
                            graph[par[curp]].pb(par[j]);
                            graph[par[j]].pb(par[curp]);
                        }
                        par[j] = par[curp];
                    }
                }
            }
        }

        //mem(vis,0);
        int cnt=0;

        for(int i=0; i<n; i++)
        {
            if(ar[i] == 1) {cnt++;continue;}
            if(!vis[par[ar[i]]])
            {
                cnt++;
                dfs(par[ar[i]]);
            }
        }
        casepf(tt);
        pf("%d\n", cnt);
    }
    return 0;
}