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

int r,c,vis[1001][1001],dis[1001][1001];
int grid[1001][1001];;

int bfs(int sr,int sc)
{
    vis[sr][sc] = 1;
    dis[sr][sc] = grid[sr][sc];
    set<pair<int,pair<int,int> > >s;
    s.insert(mp(dis[sr][sc],mp(1,1)));

        while(!s.empty())
        {
            pair<int,pair<int,int> > pp = *s.begin();
            s.erase(s.begin());

                int rr = pp.second.first;
                int cc = pp.second.second;

                if(rr == r && cc == c) return dis[rr][cc];

                for(int i=0; i<4; i++)
                {
                    int tr = rr + dir_r_4[i];
                    int tc = cc + dir_c_4[i];

                        if(tr>=1 && tr<=r && tc>=1 && tc<=c)
                        {
                            if(dis[tr][tc]>dis[rr][cc] + grid[tr][tc] && !vis[tr][tc])
                            {
                                dis[tr][tc] = dis[rr][cc] + grid[tr][tc];
                                vis[tr][tc] = 1;
                                s.insert(mp(dis[tr][tc],mp(tr,tc)));
                            }
                        }
                }
        }
}

int main()
{
    int tc;

        sf(tc);

            loop(tt,1,tc+1)
            {
                scanf("%d %d", &r,&c);

                    loop(i,1,r+1)
                    {
                        loop(j,1,c+1)sf(grid[i][j]);
                    }
                    for(int i=0; i<1001; i++)
                    {
                        for(int j=0; j<1001; j++) dis[i][j] = intinf;
                    }
                    mem(vis,0);
                    pf("%d\n", bfs(1,1));
            }
    return 0;
}