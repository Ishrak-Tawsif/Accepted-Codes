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
//pair <int,pair<int,int> > grid[1001][1001];
int grid[1001][1001];;

int dfs(int sr,int sc)
{
    vis[sr][sc] = 1;
    if(sr == r && sc == c) {/*cout<<sr<<" .. "<<sc<<" " <<dis[sr][sc]<<endl;*/return dis[sr][sr];}

        for(int i=0; i<4; i++)
        {
            int tr = sr + dir_r_4[i];
            int tc = sc + dir_c_4[i];

                if(tr>=1 && tr<=r && tc>=1 && tc<=c)
                {
                    if(!vis[tr][tc])
                    {
                        dis[tr][tc] = dis[sr][sc] + grid[tr][tc];//cout<<tr<<" "<<tc<<" " <<dis[sr][sc]<<endl;
                        dfs(tr,tc);
                    }
                }
        }
    //vis[sr][sc]=0;
    //dis[sr][sc]=0;
}

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
//cout<<rr<<" " <<cc<<endl;
                if(rr == r && cc == c) {/*cout<<dis[rr][cc]<<" ...... "<<endl;*/ return dis[rr][cc];}

                for(int i=0; i<4; i++)
                {
                    int tr = rr + dir_r_4[i];
                    int tc = cc + dir_c_4[i];//cout<<rr<<" .. "<<cc<<" .. "<<tr<<" "<<tc<<endl;
//if(tr == 3 && tc == 5) cout<<rr<<" " <<cc<<endl;
                        if(tr>=1 && tr<=r && tc>=1 && tc<=c)
                        {
                            if(/*!vis[tr][tc]*/ dis[tr][tc]>dis[rr][cc] + grid[tr][tc])
                            {
                                dis[tr][tc] = dis[rr][cc] + grid[tr][tc];
                                //cout<<rr<<" "<<cc<<" "<<tr<<" "<<tc<<" " << grid[tr][tc]<<" "<< dis[rr][cc]<<" " <<dis[tr][tc]<<endl;
                                //dfs(tr,tc);
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
                        loop(j,1,c+1)
                        {
                            sf(grid[i][j]);
                            //grid[i][j].second.first=i;
                            //grid[i][j].second.second=j;
                        }
                    }
                    for(int i=0; i<1001; i++)
                    {
                        for(int j=0; j<1001; j++) dis[i][j] = intinf;
                    }
                    pf("%d\n", bfs(1,1));
            }
    return 0;
}