#include<bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

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
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007

int n,m,diss[1<<16],vis[1<<16];
vector <int> swi[43];

int bfs()
{
    queue <int> q;
    int mask = 0;
    q.push(mask);
    diss[mask] = 0;
    vis[mask] = 1;

    while(!q.empty())
    {
        int curmask = q.front();
        q.pop();

            for(int i=0; i<m; i++)
            {
                mask = curmask;
                for(int j=0; j<swi[i].size(); j++)
                {
                    int curbulb = swi[i][j];
                    //if(!(curmask & 1<<j))
                    if(!(mask & 1<<curbulb))mask = mask | (1<<curbulb);
                    else mask = mask ^ (1<<curbulb);
                    //mask = mask ^ (1<<curbulb);
                }
                if(!vis[mask])
                {
                    vis[mask] = 1;
                    diss[mask] = diss[curmask] + 1;
                    q.push(mask);
                }
            }
    }
}

int ipow(int base,int exp)
{
    int res = 1;
    while(exp--) res *= base;

    return res;
}

void doclear()
{
    for(int i=0; i<43; i++) swi[i].clear();
    mem(vis,0);
    mem(diss,-1);
}

int main()
{//WRITE("in.txt");
    int tc;
    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%d %d", &n,&m);
        doclear();

        for(int i=0; i<m; i++)
        {
            int tot,tmp;
            sf(tot);
            while(tot--)
            {
                sf(tmp);
                swi[i].pb(tmp);
            }
        }

        bfs();

        casepf(tt);

        int query,cnt=0;
        string state;
        sf(query);

        while(query--)
        {
            cin>> state;
            int val=0;
            cnt=0;
            for(int i=state.length()-1; i>=0; i--)
            {
                val += (ipow(2,cnt) * (state[i]-'0'));
                cnt++;
            }//out(val);
            if(!vis[val]) pf("-1\n");
            else pf("%d\n", diss[val]);
        }

        pf("\n");
    }
    return 0;
}