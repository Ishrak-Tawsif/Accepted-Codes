 #include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case #%d\n",nn)
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
#define mx                      2000+5
#define mod                     1000000007

vector <int> graph[205];
int vis[205],fl,cnt[3];

void dfs(int sr,int curclr)
{
    vis[sr] = curclr;
    cnt[curclr]++;//out(sr);
        for(int i=0; i<graph[sr].size(); i++)
        {
            int vv = graph[sr][i];
            if(vis[vv] == curclr)
            {
                fl=0;
                return ;
            }
            else
            {
                if(vis[vv] == -1)dfs(vv,1-curclr);
            }
        }
}

int main()
{
    int tc,ans,u,v,n,m,clr;

    scanf("%d", &tc);

    while(tc--)
    {
        scanf("%d %d", &n,&m);

        mem(vis,-1);
        for(int i=0; i<205; i++) graph[i].clear();

        for(int i=0; i<m; i++)
        {
            scanf("%d %d", &u,&v);
            graph[u].pb(v);
            graph[v].pb(u);
        }

        clr=1,fl=1,ans=0;
        for(int i=0; i<n; i++)
        {
            if(vis[i] == -1)
            {
                cnt[0] = cnt[1] = 0;
                vis[i] = clr;
                //clr = (clr)? 0 : 1;
                dfs(i,0);
                ans += max(1,min(cnt[0],cnt[1]));
            }
        }
        (!fl)? pf("-1\n") : pf("%d\n", ans);
    }

    return 0;
}