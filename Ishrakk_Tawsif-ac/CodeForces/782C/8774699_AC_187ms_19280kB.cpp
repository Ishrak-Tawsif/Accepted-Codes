#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 200009
#define ll long long int
#define mp make_pair
#define mod 100000007

int dir_r_8[]={-1,-1,-1,0,0,1,1,1};
int dir_c_8[]={-1,0,1,-1,1,-1,0,1};
int dir_r_4[]={-1,1,0,0};
int dir_c_4[]={0,0,-1,1};

int vis[mx],n,ans[mx],clr,par[mx],max_=INT_MIN;
map<int,int>tr;
vector <int> graph[mx];

int dfs(int sr,int pre)
{
    vis[sr]=1;
    int clr=0;

        for(int i=0; i<graph[sr].size(); i++)
        {
            int v = graph[sr][i];
            if(vis[v]) continue;

                clr++;
                while(ans[sr] == clr || ans[pre] == clr) clr++;
                ans[v]=clr;
                if(max_<clr) max_=clr;
                dfs(v,sr);
        }
}

int main()
{
    sf(n);
    int u,v;

        loop(i,n-1)
        {
            scanf("%d %d", &u,&v);
            graph[u].pb(v);
            graph[v].pb(u);
        }

        ans[1]=1;
        //clr[1]=1;
        //par[1]=1;
        dfs(1,0);
        pf("%d\n", max_);
        for(int i=1; i<n; i++) pf("%d ", ans[i]) ;
        pf("%d\n",ans[n]);
    return 0;
}