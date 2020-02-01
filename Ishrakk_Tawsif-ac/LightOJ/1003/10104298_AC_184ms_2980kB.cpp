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
#define mx                      20005
#define mod                     1000000007

int n,m,dis[mx],vis[mx];
vector <int> graph[mx];
map <string,int> track;
string a,b;
bool res;

///cycle finding.If cycle exist ans is no else yes
int dfs(int sr,int id)
{
    vis[sr] = id;

        for(int i=0; i<graph[sr].size(); i++)
        {
            int v = graph[sr][i];

                if(vis[v] != id)
                {
                    dis[v] = dis[sr] + 1;
                    dfs(v,id);
                }
                else
                {
                    res=true;
                }
        }
}

int main()
{
    int tc,id;

    sf(tc);

        loop(tt,1,tc+1)
        {
            sf(m);

                for(int i=0; i<mx; i++){graph[i].clear();vis[i]=0;}
                track.clear();

                int in=0;
                loop(i,0,m)
                {
                    cin>> a>> b;
                    if(track[a] == 0){track[a]=in++;}
                    if(track[b] == 0){track[b]=in++;}
                    graph[track[a]].pb(track[b]);
                }

                dis[0] = 0;
                id = 0;
                res = false;

                for(int i=0; i<=in; i++)
                {//pf("\n");for(int i=0;i<=in; i++)cout<< " " << vis2[i];cout<<endl;
                    if(!vis[i]){ dfs(i,++id); if(res==true) {break;}}
                }

                casepf(tt);//cout<<res<<endl;
                (res == false)? pf("Yes\n") : pf("No\n");
        }

    return 0;
}