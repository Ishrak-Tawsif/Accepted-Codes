#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 103
#define ll long long int
#define mp make_pair
#define mod 100000007

int dir_r_8[]={-1,-1,-1,0,0,1,1,1};
int dir_c_8[]={-1,0,1,-1,1,-1,0,1};
int dir_r_4[]={-1,1,0,0};
int dir_c_4[]={0,0,-1,1};

vector <pair <int,int> > graph[mx];
bool vis[103][103];
int dis[103][103],price[103];

struct Node
{
    int uu , uo , uco ;
};

class cmp
{
public:
    bool operator () (Node A,Node B)
    {
        if(A.uco==B.uco) return A.uo < B.uo ;
        else return A.uco > B.uco ;
    }
};

int bfs(int s,int des,int cap)
{
    loop(i,mx)
    {
        loop(j,mx)
        {
            vis[i][j]=0;
            dis[i][j]=INT_MAX;
        }
    }

         priority_queue <Node,vector<Node>,cmp> q;
         Node nnd;
         dis[s][0]=0;
         nnd.uu=s,nnd.uo=0,nnd.uco=0;
         q.push(nnd); ///cost,how much oil takes,city

            while(!q.empty())
            {
                pair<int,pair<int,int> > temp;
                //temp = q.front(); q.pop();
                int ucost=q.top().uco,uoil=q.top().uo,u=q.top().uu; q.pop();
//cout<<u << " " <<uoil << " " << ucost<<endl;
                    if(u == des) return ucost;
                    if(vis[u][uoil]) continue;

                        vis[u][uoil]=1;
                        loop(i,graph[u].size())
                        {
                            int v=graph[u][i].first,vdis=graph[u][i].second;
                            //int vcost = vdis *

                            for(int j=vdis; j<=cap; j++)
                            {
                                int diff=0;
                                if(j>uoil) diff=j-uoil;
//cout <<vdis<<" "<<uoil<<" "<<diff<<".."<<endl;
                                    int prc=(price[u]*diff)+ucost;
//cout<<"prc : "<<prc<<" " <<price[u]<<" "<<u<<endl;
                                        if(dis[v][j-vdis]>prc)
                                        {
                                            dis[v][j-vdis]=prc;
                                            nnd.uu=v,nnd.uo=j-vdis,nnd.uco=prc;
                                            q.push(nnd);
                                            //cout<<v<<" " <<j-vdis << " " << prc<<endl;
                                        }
                            }//system("pause");
                        }
            }
     return -1;
}

int main()
{
    int tc,n,m,u,v,c;

        sf(tc);

            loop1(tt,tc)
            {
                scanf("%d %d", &n,&m);

                    //loop(i,mx) graph[i].clear();

                    loop(i,n) {sf(price[i]); graph[i].clear();}

                    loop(i,m)
                    {
                        scanf("%d %d %d", &u,&v,&c);
                        graph[u].pb(mp(v,c));
                        graph[v].pb(mp(u,c));
                    }
                    int queries,cap,s,d;
                        sf(queries);

                            pf("Case %d:\n",tt);

                            loop(i,queries)
                            {
                                scanf("%d %d %d", &cap,&s,&d);
                                int ans = bfs(s,d,cap);

                                if(ans==-1) pf("impossible\n",tt);
                                else pf("%d\n",ans);
                            }
            }
    return 0;
}