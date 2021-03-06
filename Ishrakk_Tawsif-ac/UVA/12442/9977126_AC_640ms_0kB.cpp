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


vector <int> graph[50005];
int cnt,vis[50005],dis[50005],vis2[50005];

int dfs(int sr)
{
    vis[sr]=1;
    vis2[sr]=1;

        for(int i=0; i<graph[sr].size(); i++)
        {
            int v = graph[sr][i];

                if(!vis2[v])
                {
                    //vis[v] = 1;
                    dis[v] = dis[sr] + 1;
                    cnt = max(cnt,dis[v]);
                    dfs(v);
                }
        }
    vis2[sr]=0;
}

int main()
{
    int tc,n,u,v;
        sf(tc);

            loop(tt,1,tc+1)
            {
                for(int i=0; i<50005;i++){graph[i].clear();vis[i]=0;}

                sf(n);

                    loop(i,0,n)
                    {
                        scanf("%d %d", &u,&v);
                        graph[u].pb(v);
                    }


                    int ans=(-1*intinf),in;
                    loop(i,1,n+1)
                    {
                        if(!vis[i])
                        {
                            cnt=INT_MIN;
                            dis[i]=0;
                            dfs(i);//cout<<i<<" " <<cnt<<endl;
                            if(cnt>ans)
                            {
                                in=i;
                                ans=cnt;
                            }
                        }
                    }

                pf("Case %d: %d\n",tt,in);
            }
    return 0;
}