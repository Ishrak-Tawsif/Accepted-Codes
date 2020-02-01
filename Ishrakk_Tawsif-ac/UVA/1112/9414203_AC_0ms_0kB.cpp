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
#define mx                      5005
#define mod                     100000007
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())

int dir_r_4[] = {0, 0, 1, -1};
int dir_c_4[] = {1, -1, 0, 0};

vector <int> graph[101];
int vis[101],dis[101],wei[101][101];

int dikjstra(int sr)
{
    vis[sr] = 1;
    dis[sr] = 0;
    set <pair<int,int> > s;
    s.insert(mp(0,sr));

        while(!s.empty())
        {
            pair <int,int> temp = *s.begin();
            s.erase(s.begin());

                int udis = temp.first;
                int u = temp.second;

                    for(int i=0; i<graph[u].size(); i++)
                    {
                        int v = graph[u][i];

                            if(!vis[v] && dis[v]>wei[u][v]+udis)
                            {
                                vis[v] = 1;//cout<<v<<" "<<wei[u][v] + udis<<endl;
                                dis[v] = wei[u][v]+udis;
                                s.insert(mp(dis[v],v));
                            }
                    }
        }
}

int main()
{
    int tc,time,ex,m,n,u,v,cst;
        //WRITE("in.txt");
        sf(tc);

            loop(tt,1,tc+1)
            {
                loop(i,0,101) { vis[i]=0; dis[i] = intinf; graph[i].clear();}
                scanf("%d %d %d %d", &n,&ex,&time,&m);

                    loop(i,1,m+1)
                    {
                        scanf("%d %d %d", &u,&v,&cst);
                        wei[v][u] = cst;
                        graph[v].pb(u);
                    }
                    dikjstra(ex);
                    int cnt=0;
                    for(int i=1; i<=n; i++) {/*cout<<dis[i]<<endl;*/if(dis[i]<=time? cnt++ : cnt=cnt);}
                    if(tt!=tc? pf("%d\n\n",cnt) : pf("%d\n",cnt));
            }

    return 0;
}

/*
1
4
2
1
8
1 2 1
1 3 1
2 1 1
2 4 1
3 1 1
3 4 1
4 2 1
4 3 1
*/