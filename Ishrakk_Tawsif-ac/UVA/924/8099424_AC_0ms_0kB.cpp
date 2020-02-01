#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 2503
#define ll long long int
#define mp make_pair
#define mod 100000007


vector <int> graph[mx];
int vis[mx],dis[mx],level[mx],fl;

int bfs(int s)
{
    queue <int> q;
    q.push(s);
    vis[s]=1;
    dis[s]=0;

        while(!q.empty())
        {
            int u=q.front(); q.pop();

                for(int i=0; i<graph[u].size(); i++)
                {
                    int v=graph[u][i];
                    fl=1;
                        if(!vis[v])
                        {
                            dis[v]=dis[u]+1;
                            level[dis[v]]++;
                            vis[v]=1;
                            q.push(v);
                        }
                }
        }
}

int main()
{
    int emp,tc,con,temp;
        //sf(tc);
            //loop1(tt,tc)
            //{
                sf(emp);
                loop(i,emp){
                    //int con,temp;
                    sf(con);
                        loop(j,con)
                        {
                            sf(temp);
                            graph[i].pb(temp);
                        }
                }
                sf(tc);
                loop1(tt,tc)
                {
                    for(int i=0; i<mx; i++){vis[i]=0; dis[i]=0; level[i]=0;}
                    sf(temp);
                    fl=-1;
                    bfs(temp);
                    int max_=INT_MIN,day;
                    for(int i=0; i<mx; i++){
                        if(max_<level[i]){
                            max_=level[i];
                            day=i;
                        }
                    }
                    if(fl==-1)pf("0\n");
                    else pf("%d %d\n", max_,day);
                }

    return 0;
}