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

int dir_r_8[]={-1,-1,-1,0,0,1,1,1};
int dir_c_8[]={-1,0,1,-1,1,-1,0,1};
int dir_r_4[]={-1,1,0,0};
int dir_c_4[]={0,0,-1,1};

//int row,col,r,c,cost[21][21],dis[21][21],vis[21][21],dp[21][1<<21],len;
//string grid[21];
//vector <pair<int,int> >vv,cc;



/*int time_needed()
{
    double end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout<<cpu_time_used<<endl;
}*/

/*struct order
{
    int s,e;

        bool operator < (const order &x) const
        {
            //if(s == x.s) return e<x.e;
            //else
                return e<x.e;
        }
};*/

string grid[203];
int r,c,jr,jc,vis[203],dis[203][203];
vector <pair<int,int> > fire;

void spread_fire()
{//cout<<".."<<endl;
    int len=fire.size();
        //cout<<len<<endl;
        for(int i=0; i<len; i++)
        {
            int tr=fire[i].first;
            int tc=fire[i].second;

            for(int j=0; j<4; j++)
            {
                int rr=tr+dir_r_4[j];
                int cc=tc+dir_c_4[j];

                    if(rr>=0 && rr<r && cc>=0 && cc<c)
                    {
                        if(grid[rr][cc]!='F' && grid[rr][cc]!='#')
                        {
                            fire.pb(mp(rr,cc));
                            grid[rr][cc]='F';
                        }
                    }
            }
        }
}

int bfs(int sr,int sc)
{
    queue<pair<int,int> >q;
    //vis[sr][sc]=1;
    dis[sr][sc]=0;
    q.push(mp(sr,sc));

        while(!q.empty())
        {
            pair<int,int> temp=q.front();
            q.pop();

                int u=temp.first;
                int v=temp.second;//cout<<u<<" "<<v<<endl;

                if((u==(r-1) || v==(c-1) || u==0 || v==0)) {return dis[u][v];}

                    if(!vis[dis[u][v]])
                        {
                            vis[dis[u][v]]=1;
                            spread_fire();
                    }

                    for(int i=0; i<4; i++)
                    {
                        int tr=u+dir_r_4[i];
                        int tc=v+dir_c_4[i];
                        //if(tr == 4 && tc==7) cout<<"right"<<endl;
                            if(tr>=0 && tr<r && tc>=0 && tc<c)
                            {
                                if(grid[tr][tc] == '.')
                                {
                                    grid[tr][tc]='#';
                                    dis[tr][tc]=dis[u][v]+1;
                                    q.push(mp(tr,tc));
                                }
                            }
                    }
                    /*for(int i=0; i<r; i++)
                    {
                        for(int j=0; j<c; j++) cout<<grid[i][j];
                        cout<<endl;
                    }*/
        }
    return -1;
}
int main()
{
    int tc;
    //int rr=2,cc=2;for(int i=0; i<4; i++) cout<<rr+dir_r_6[i]<<" "<<cc+dir_c_6[i]<<endl;
        sf(tc);

            loop1(tt,tc)
            {
                scanf("%d %d", &r,&c);
                fire.clear();

                    loop(i,r)
                    {
                        cin>> grid[i];
                        loop(j,c){
                            if(grid[i][j] == 'J'){jr=i; jc=j;}
                            else if(grid[i][j]=='F') fire.pb(mp(i,j));
                        }
                    }

                    memset(vis,0,sizeof(vis));
                    int ans=bfs(jr,jc);
                    if(ans!=-1)pf("Case %d: %d\n",tt,++ans);
                    else pf("Case %d: IMPOSSIBLE\n",tt);

            }
    return 0;
}