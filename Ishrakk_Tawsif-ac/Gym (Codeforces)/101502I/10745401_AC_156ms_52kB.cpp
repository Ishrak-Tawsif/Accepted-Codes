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
#define intinf                  1e9
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

int cnt[255][11],vis[255],dis[255];
vector <int> graph[255];

void clear_()
{
    for(int i=0; i<255; i++)
    {
        graph[i].clear();
        vis[i] = 0;
        dis[i] = 0;
        for(int j=0; j<11; j++) cnt[i][j]=0;
    }
}

int bfs(int sr,int des)
{
    queue <pair<int,int> > q;
    vis[sr] = 1;
    q.push(mp(sr,0));
    dis[sr] = 0;

        while(!q.empty())
        {
            pair <int,int> temp = q.front();
            q.pop();

            int u = temp.first;
            int udis = temp.second;
//cout<<u<<endl;
            if(u == des) return udis;

                for(int i=0; i<graph[u].size(); i++)
                {
                    int v = graph[u][i];

                        if(!vis[v])
                        {
                            vis[v] = 1;
                            dis[v] = udis+1;
                            q.push(mp(v,udis+1));
                        }
                        /*else if(dis[v]>udis+1)
                        {
                            dis[v] = udis + 1;
                            q.push(mp(v,dis[v]));
                        }*/
                }
        }
    return -1;
}

int main()
{
    int tc;

    sf(tc);

    int n,s,e;

    while(tc--)
    {
        scanf("%d %d %d", &n,&s,&e);

        //mem(cnt,0);

        clear_();

        string str;
        loop(i,0,n)
        {
            cin>> str;
            for(int j=0; j<str.size(); j++)
            {
                int dig = str[j] - '0'; //out(dig);
                cnt[i][dig] ++;
            }
        }
        for(int i=0; i<n; i++)
        {
            //int cont = 0;
            for(int j=0; j<n; j++)
            {//cout<< i << " ........... " << j << endl;
                int cont = 0;
                //if(i == j) continue;
                for(int k=0; k<=9 ;k ++)
                {
                    cont += min(cnt[i][k],cnt[j][k]);
                    //cout<< k << " " << min(cnt[i][k],cnt[j][k])<<endl;
                }//cout<<i<<" " << j << " " << cont << endl;
                if(cont==17) {graph[i].pb(j);}
            }//cout<<cont<<endl;
            //if(cont>=17)
        }
        cout<<bfs(--s,--e)<<endl;
    }
    return 0;
}