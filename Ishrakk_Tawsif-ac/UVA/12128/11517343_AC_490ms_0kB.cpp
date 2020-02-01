#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case #%d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     1e5
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007


int dirx[8]={0,0,1,-1,1,1,-1,-1};
int diry[8]={1,-1,0,0,1,-1,1,-1};

int n,xx,yy,sx,sy,dx,dy,isenemy[1005][1005],dist[1005][1005],vis[1005][1005],diss[1005][1005],visited[1005][1005];
int ansdist=-inf,ansroute = inf;

struct ST
{
    int x, y;
};

queue <ST> enemy;

int bfs(int mindist)
{

    for(int i=0; i<1005; i++)
    {
        for(int j=0; j<1005; j++)
        {
            dist[i][j] = inf;
            dist[i][j] = inf;
            vis[i][j] = 0;
            vis[i][j] = 0;
        }
    }

    queue <pair<int,int> > q;
    q.push(mp(sx,sy));
    vis[sx][sy] = 1;
    dist[sx][sy] = 0;

        while(!q.empty())
        {
            pair <int,int> temp = q.front();
            q.pop();
            vis[temp.first][temp.second] = 0;

            for(int i=0; i<4; i++)
            {
                int tr = temp.first + dirx[i];
                int tc = temp.second + diry[i];

                if(tr>=0 && tr<xx && tc>=0 && tc<yy)
                {

                    //if(diss[tr][tc]<minidis) continue;

                    if(diss[tr][tc]>=mindist && dist[tr][tc]>dist[temp.first][temp.second] + 1)
                    {
                        //vis[tr][tc] = 1;
                        dist[tr][tc] = dist[temp.first][temp.second] + 1;
                        if(!vis[tr][tc]) vis[tr][tc]=1,q.push(mp(tr,tc));
                    }
                }
            }
        }
    return dist[dx][dy];;
}

int check(int mindist)
{
    if(diss[sx][sy]<mindist) return 0;

    mem(vis,0);
    queue <pair<int,int> > q;
    q.push(mp(sx,sy));
    vis[sx][sy] = 1;

        while(!q.empty())
        {
            pair<int,int> temp = q.front();
            q.pop();

            int ur = temp.first;
            int uc = temp.second;

            if(ur == dx && uc == dy) return 1;

                for(int i=0; i<4; i++)
                {
                    int tr = ur + dirx[i];
                    int tc = uc + diry[i];

                        if(tr>=0 && tr<xx && tc>=0 && tc<yy)
                        {
                            if(!vis[tr][tc])
                            {
                                if(diss[tr][tc]>=mindist)
                                {
                                    vis[tr][tc] = 1;
                                    q.push(mp(tr,tc));
                                }
                            }
                        }
                }
        }
}

void setclear()
{
    //enemy.clear();
    for(int i=0; i<1005; i++)
    {
        for(int j=0; j<1005; j++)
        {
            dist[i][j] = inf;
            dist[i][j] = inf;
            diss[i][j] = 0;
            vis[i][j] = 0;
            vis[i][j] = 0;
            isenemy[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

int main()
{//WRITE("in.txt");
    int tc;

    scanf("%d", &tc);

    for(int tt=1; tt<=tc; tt++)
    {

        setclear();

        scanf("%d %d %d", &n,&xx,&yy);
        scanf("%d %d %d %d", &sx,&sy,&dx,&dy);

        ST get;

        //mem(isenemy,0);
        //mem(diss,0);

        for(int i=0; i<n; i++)
        {
            scanf("%d %d", &get.x,&get.y);
            enemy.push(get);
            isenemy[get.x][get.y] = 1;
        }

        while(!enemy.empty())
        {//out("2");
            int curx = enemy.front().x;
            int cury = enemy.front().y;
            enemy.pop();

            for(int i=0; i<4; i++)
            {
                int tx = curx+dirx[i];
                int ty = cury+diry[i];
//cout<<tx<<" "<<ty<<endl;
                if(tx>=0 && tx<xx && ty>=0 && ty<yy)
                {

                    if(!isenemy[tx][ty] && !visited[tx][ty])
                    {
                        visited[tx][ty] = 1;
                        diss[tx][ty] = diss[curx][cury] + 1;
                        get.x = tx;
                        get.y = ty;
                        enemy.push(get);
                    }
                }
            }
        }//out("1");

        /*bfs(0,sx,sy);
        bfs(1,dx,dy);

        int maxdist = -inf,minroute = inf;
        for(int i=0; i<=xx; i++)
        {
            for(int j=0; j<=yy; j++)
            {
                int tot = dist[0][i][j] + dist[1][i][j];
                int curdis = diss[i][j];

                if(tot<inf)
                {
                    if(curdis>maxdist)
                    {
                        maxdist = curdis;cout<<i<<" "<<j<<endl;
                        minroute = tot;
                    }
                    if(curdis == tot)
                    {
                        minroute = min(minroute,tot);
                    }
                }
            }
        }
        pf("%d %d\n", maxdist,minroute);*/

        int st = 0,en = 1000005,ans,mid;

        while(st<=en)
        {
            mid = (st + en)>> 1;//cout<<mid<<" ";
            if(check(mid))
            {//out("1");
               ans = mid;
               st = mid + 1;
            }
            else en = mid - 1/*,out("0")*/;
        }

    ansroute = bfs(ans);
    pf("%d %d\n", ans,ansroute);

    }
    return 0;
}