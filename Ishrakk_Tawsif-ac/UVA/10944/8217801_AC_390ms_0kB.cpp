#include<bits/stdc++.h>
using namespace std;


int dir_r[]={-1,-1,-1,0,0,1,1,1};
int dir_c[]={-1,0,1,-1,1,-1,0,1};
int start,cost [23][23],vis[23][23],dis[23][23],row,col,len,dp[23][1<<21],lim ;
string str[23];

int bfs(int sr,int sc,int dr,int dc)
{
    queue<int>q;
    dis[sr][sc]=0;
    vis[sr][sc]=1;
    q.push(sr);
    q.push(sc);

        while(!q.empty())
        {
            int rr=q.front(); q.pop();
            int cc=q.front(); q.pop();

            if(rr==dr && cc==dc) return dis[rr][cc];

                for(int j=0; j<8; j++)
                {
                    int temp_r=rr+dir_r[j];
                    int temp_c=cc+dir_c[j];
//cout<<rr<<" "<<cc<<" "<<dis[rr][cc]<<endl;
                        if(temp_r>=0 && temp_r<row && temp_c>=0 && temp_c<col)
                        {
                            if(!vis[temp_r][temp_c])
                            {
                                vis[temp_r][temp_c]=1;
                                dis[temp_r][temp_c]=dis[rr][cc]+1;
                                q.push(temp_r);
                                q.push(temp_c);
                                //cout<<dis[temp_r][temp_c]<<endl;
                            }
                        }
                }
        }
}

int bitmask_dp(int i,int mask)
{
    if(mask==lim) {/*cout<<i<<" "<<len<<" .. "<<cost[i][len]<<endl;*/return cost[len][i];}
    if(dp[i][mask]!=-1) return dp[i][mask];

        int ans=INT_MAX;

            for(int j=0; j<len; j++)
            {
                if(!(mask & 1<<j))
                   {//cout<<i<<" "<<j<<" "<<cost[i][j]<<endl;
                       ans=min(ans,(cost[i][j]+(bitmask_dp(j,(mask | 1<<j)))));
                   }//if(i==3)cout<<i<<" "<<j<<" ... "<<ans<<endl;
            }
        return dp[i][mask]=ans;
}

int main()
{
    vector<pair<int,int> >vv;
//int rr=2,cc=2; for(int i=0; i<8; i++){cout<<rr+dir_r[i]<<" "<<cc+dir_c[i]<<endl;}
        while(scanf("%d %d", &row,&col)==2)
        {
            int rrr,ccc;
            vv.clear();
            
            for(int i=0; i<row; i++){
                cin>> str[i];
                   for(int j=0; j<col; j++){
                        if(str[i][j]=='#')
                            vv.push_back(make_pair(i,j));

                        else if(str[i][j]=='L'){
                            rrr=i;
                            ccc=j;
                        }
                   }
            }//cout<<start<<endl;
            len=vv.size();
                if(len==0) cout<<0<<endl;
                else{

                vv.push_back(make_pair(rrr,ccc));

                memset(cost,-1,sizeof(cost));//cout<<cost[0][0]<<endl;
                    for(int i=0; i<=len; i++){
                        for(int j=0; j<=len; j++){
                            int sr=vv[i].first,sc=vv[i].second;
                            int dr=vv[j].first,dc=vv[j].second;
                                memset(vis,0,sizeof(vis));
                                if(cost[i][j]==-1)cost[i][j]=cost[j][i]=bfs(sr,sc,dr,dc);
                                //cout<<sr<<" "<<sc<<" "<<dr<<" "<<dc<<" "<<cost[i][j]<<endl;}
                        }
                    }
                    memset(dp,-1,sizeof(dp));
                    lim=(1<<len)-1;
                    cout<<bitmask_dp(len,0)<<endl;
            }
        }
    return 0;
}