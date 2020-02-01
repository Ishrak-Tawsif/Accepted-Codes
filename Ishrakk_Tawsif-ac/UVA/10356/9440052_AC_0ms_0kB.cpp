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
#define intinf                  1e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())

int dir_r_4[] = {0, 0, 1, -1};
int dir_c_4[] = {1, -1, 0, 0};

vector <pair<int,int> > graph[1005];
int vis[2][1005],dis[2][1005],cnt[2][1005];


int dikjstra(int sr,int des,int tp)
{
    vis[tp][sr] = 1;
    dis[tp][sr] = 0;
    cnt[tp][sr] = 0;
    set <pair<int,pair<int,int> > >s;
    s.insert(mp(dis[tp][sr],mp(sr,tp)));

        while(!s.empty())
        {
            pair<int,pair<int,int> >p = *s.begin();
            s.erase(s.begin());

                int udis = p.first;
                int u = p.second.first;
                int type = p.second.second;

                    //if(u == des) return dis[tp][u];

                    for(int i=0; i<graph[u].size(); i++)
                    {
                        int v = graph[u][i].first;
                        int uvdis = graph[u][i].second;

                            if(/*!vis[1-type][v] &&*/ dis[1-type][v]>udis + uvdis)
                            {
                                vis[1-type][v] = 1;
                                cnt[1-type][v] = cnt[tp][u] + 1;
                                dis[1-type][v] = udis + uvdis;
                                s.insert(mp(dis[1-type][v],mp(v,1-type)));
                            }
                    }
        }
     //return -1;
}

int main()
{//WRITE("in.txt");
    int n,m,u,v,cst,tt=0;

        while(scanf("%d %d", &n,&m) == 2)
        {
            if(m == 0 && n == 1){pf("Set #%d\n0\n",++tt);continue;}
            for(int i=0; i<1005; i++)
            {
                vis[0][i] = 0;
                vis[1][i] = 0;
                dis[0][i] = intinf;
                dis[1][i] = intinf;
                graph[i].clear();
                cnt[0][i] = 0;
                cnt[1][i] = 0;
            }

            loop(i,0,m)
            {
                scanf("%d %d %d", &u,&v,&cst);
                //if(u==0 && v==n-1) continue;
                graph[u].pb(mp(v,cst));
                graph[v].pb(mp(u,cst));
            }
            dikjstra(0,n-1,0);

            int ans = dis[0][n-1];

            if(ans == intinf? pf("Set #%d\n?\n",++tt) : pf("Set #%d\n%d\n",++tt,ans ));

            //dikjstra(n-1,0,1);

            /*int ans=intinf,temp;
            for(int i=0; i<n; i++)
            {
                if(dis[0][i] != intinf && dis[1][i] != intinf)
                {
                    temp = dis[0][i] + dis[1][i];
                    int koyta = cnt[0][i] + cnt[1][i];
cout<<temp<<"..." <<koyta<<endl;
                    //if(koyta>=2 && koyta%2 == 0)
                    //{
                        if(ans>temp) ans = temp;
                    //}
                }
            }
            if(ans == intinf? pf("Set #%d\n?\n",++tt) : pf("Set #%d\n%d\n",++tt,ans ));//if(tt==20) system("pause");*/
        }
    return 0;
}