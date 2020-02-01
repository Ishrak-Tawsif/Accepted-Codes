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
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007


int dx[8] = {1,-1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};

int dirr[] = {-1,-1,0,0,1,1};
int dirc[] = {0,1,-1,1,-1,0};

//int n,ar[200005],ar2[200005],dp[10005][3];

int nod,vis[1003],cnt;
vector <int> graph[1003];

void dfs(int sr)
{
    //vis[sr] = 1;

        for(int i=0; i<graph[sr].size(); i++)
        {//cout<<sr<<" "<<graph[sr][i]<<" "<<vis[graph[sr][i]][tc]<<endl;
            if(!vis[graph[sr][i]])
            {
                cnt++;
                vis[graph[sr][i]]=1;
                dfs(graph[sr][i]);
            }
        }
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
	int tt=0;
	while(sf(nod) == 1 && nod)
    {
        int t1,t2;
        for(int i=0; i<1003; i++) graph[i].clear();
        while(sf(t1) == 1 && t1)
        {
            while(sf(t2) == 1 && t2) graph[t1].pb(t2);
        }

        int tc;

        sf(tc);

        while(tc--)
        {
            cnt=0;
            int sr;
            sf(sr);
            mem(vis,0);
            dfs(sr);//cout<<tt<<endl;
            pf("%d",nod-cnt);
            for(int i=1; i<=nod; i++)
            {
                if(!vis[i])pf(" %d",i);
            }
            pf("\n");
        }
    }
	return 0;
}