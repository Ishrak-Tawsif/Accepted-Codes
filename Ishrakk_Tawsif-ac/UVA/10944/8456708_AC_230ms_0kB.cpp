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

int row,col,r,c,cost[21][21],dis[21][21],vis[21][21],dp[21][1<<21],len;
string grid[21];
vector <pair<int,int> >vv,cc;

int dir_r[]={-1,-1,-1,0,0,1,1,1};
int dir_c[]={-1,0,1,-1,1,-1,0,1};

/*int time_needed()
{
    double end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout<<cpu_time_used<<endl;
}*/

int bfs(int sr,int sc,int dr,int dc)
{
    dis[sr][sc]=0;
    memset(vis,0,sizeof(vis));

        queue<int>q;
        q.push(sr);
        q.push(sc);
        vis[sr][sc]=1;

            while(!q.empty())
            {
                int tr=q.front(); q.pop();
                int tc=q.front(); q.pop();

                if(tr==dr && tc==dc){break;}

                    for(int i=0; i<8; i++)
                    {
                        int rrr=tr+dir_r[i];
                        int ccc=tc+dir_c[i];
                            if(rrr>=0 && rrr<row && ccc>=0 && ccc<col)
                        {
                            if(!vis[rrr][ccc])
                            {
                                vis[rrr][ccc]=1;
                                dis[rrr][ccc]=dis[tr][tc]+1;
                                q.push(rrr);
                                q.push(ccc);
                            }
                        }
                    }
            }
     return dis[dr][dc];
}

int bitmask(int i,int mask)
{
    if(mask == ( (1<< len)-1)) return cost[len][i];
    if(dp[i][mask]!=-1) return dp[i][mask];

    int ans=99999999;

        for(int j=0; j<len; j++)
        {

           if(!(mask & 1<<j))
           {
               ans=min(ans,bitmask(j,mask | 1<<j)+cost[i][j]);
           }
        }//cout<<ans<<endl;
   return dp[i][mask]=ans;
}

int main()
{
    while(scanf("%d %d",&row,&col)==2)
    {
        vv.clear();

        for(int i=0; i<row; i++)
        {
            cin>>grid[i];

                for(int j=0; j<col; j++)
                {
                    if(grid[i][j] == 'L'){r=i; c=j;}
                    else if(grid[i][j] == '#') {vv.pb(mp(i,j));}
                }
        }
        len=vv.size();
        if(len==0)pf("0\n");
        else{
        vv.pb(mp(r,c));
        memset(cost,-1,sizeof(cost));
        memset(dp,-1,sizeof(dp));

            for(int i=0; i<=len; i++)
            {
                for(int j=0; j<=len; j++){
                        if(cost[i][j]==-1){
                        cost[i][j]=cost[j][i]=bfs(vv[i].first,vv[i].second,vv[j].first,vv[j].second);
                        //cout<<vv[i].first<<" "<<vv[i].second<<" "<<vv[j].first<<" "<<vv[j].second<<" "<<cost[i][j]<<endl;
                        }
                }
            }

        cout<<bitmask(len,0)<<endl;
        }
    }
    return 0;
}