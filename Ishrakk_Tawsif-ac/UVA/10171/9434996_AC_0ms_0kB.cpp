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

vector <pair<int,int> > graphs[31],graphm[31];

int vis[2][31],dis[2][31];

int dikjstra(int sr,int tp)
{
    vis[tp][sr] = 1;
    dis[tp][sr] = 0;
    queue<pair<int,int> >q;
    q.push(mp(dis[tp][sr],sr));

        while(!q.empty())
        {
            int udis=q.front().first;
            int u = q.front().second;
            q.pop();

                    if(tp == 0)
                    {
                        for(int i=0; i<graphs[u].size(); i++)
                        {
                            int v=graphs[u][i].first;
                            int uvdis=graphs[u][i].second;//cout<<v<<" " <<udis<<endl;

                                if(!vis[tp][v] && dis[tp][v]>udis+uvdis)
                                {
                                    dis[tp][v] = udis + uvdis;
                                    vis[tp][v] = 1;
                                    q.push(mp(dis[tp][v],v));
                                }
                        }
                    }
                    else
                    {
                        for(int i=0; i<graphm[u].size(); i++)
                        {
                            int v=graphm[u][i].first;
                            int uvdis=graphm[u][i].second;//cout<<v<<" " <<udis<<endl;

                                if(!vis[tp][v] && dis[tp][v]>udis+uvdis)
                                {
                                    dis[tp][v] = udis + uvdis;
                                    vis[tp][v] = 1;
                                    q.push(mp(dis[tp][v],v));
                                }
                        }
                    }

        }
}

int main()
{//WRITE("in.txt");
    int n,cst,tt=0;
    char type,age,u,v,sha,mig;

        while(sf(n) == 1 && n)
        {
          tt++;
          for(int i=1; i<=30; i++)
          {
                vis[0][i]=vis[1][i]=0; dis[0][i]=dis[1][i] = intinf;
                graphs[i].clear();
                graphm[i].clear();
          }


          loop(i,0,n)
          {

              cin>> age>> type>> u>> v>> cst;

                    int uu=u-64,vv=v-64;//cout<<uu<<" " << vv << endl;
                    if(age == 'Y')
                    {
                        if(type == 'U') {graphs[uu].pb(mp(vv,cst));}
                        else {
                            graphs[uu].pb(mp(vv,cst));
                            graphs[vv].pb(mp(uu,cst));
                        }
                    }
                    else
                    {
                        if(type == 'U')graphm[uu].pb(mp(vv,cst));
                        else
                        {
                            graphm[uu].pb(mp(vv,cst));
                            graphm[vv].pb(mp(uu,cst));
                        }
                    }
          }

                cin>> sha>> mig;

                dikjstra(sha-64,0);//for(int i=1; i<=n; i++) cout<<dis[0][i]<<endl;
                dikjstra(mig-64,1);//for(int i=1; i<=n; i++) cout<<dis[1][i]<<endl;

                int min_=intinf;
                vector<int>ans;
                for(int i=1; i<=30; i++)
                {//cout<<i<<endl;
                    if(min_>dis[0][i]+dis[1][i]){min_ = dis[0][i]+dis[1][i];ans.clear(); ans.pb(i);}
                    else if(min_ == dis[0][i]+dis[1][i]) ans.pb(i);
                }
                ///char ccc = (char) (ans+64);//if(tt == 145) system("pause");
                if(min_ == intinf) pf("You will never meet.\n");
                else
                {
                    pf("%d", min_);
                    for(int i=0; i<ans.size(); i++)pf(" %c", (char)(ans[i]+64));
                    pf("\n");
                }
        }
    return 0;
}