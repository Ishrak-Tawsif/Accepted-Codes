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

vector <pair<int,int> >graph[1005];
int vis[1005],dist[1005],fl,n;

bool bellmanford()
{
    //loop(i,0,1005) dist[i]=intinf;
    dist[0] = 0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<graph[j].size(); k++)
            {
                int v=graph[j][k].first;
                int vcost=graph[j][k].second;

                    if(dist[v]>dist[j]+vcost) dist[v] = dist[j]+vcost;
            }
        }
    }

    bool cycle=false;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<graph[i].size(); j++)
        {
            int v = graph[i][j].first;
            int vcost=graph[i][j].second;

            if(dist[v]>dist[i]+vcost)return cycle=true;
        }
    }
    return cycle == true;
}

int main()
{
    int tc,m,u,v,c;

        sf(tc);

            loop(tt,1,tc+1)
            {
                scanf("%d %d",&n,&m);

                    for(int i=0; i<1005; i++)
                    {
                        graph[i].clear();
                        dist[i]=intinf;
                    }

                    loop(i,0,m)
                    {
                        scanf("%d %d %d", &u,&v,&c);
                        graph[u].pb(mp(v,c));
                    }
                    fl=0;
                    //cout<<"gfrwgft";
                    (bellmanford())? pf("possible\n") : pf("not possible\n");
            }
    return 0;
}

/*

5
5 6
0 1 1000
1 2 15
2 1 -15
0 3 -30
3 4 -60
4 0 20

5 6
0 1 1000
1 2 15
2 1 -15
0 3 -30
3 4 60
4 0 20
*/