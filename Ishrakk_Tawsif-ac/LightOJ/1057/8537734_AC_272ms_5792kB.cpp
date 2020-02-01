#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 1000000005
#define ll long long int
#define mp make_pair
#define mod 100000007

int dir_r_8[]={-1,-1,-1,0,0,1,1,1};
int dir_c_8[]={-1,0,1,-1,1,-1,0,1};
//int dir_r_4[]={-1,1,0,0};
//int dir_c_4[]={0,0,-1,1};

string str[21];
vector <pair<int,int> >vv;
int arr[20][20],vis[20][20],dis[20][20],n,m;

int bfs(int sr,int sc,int dr,int dc)
{
    queue <pair<int,int> > q;
    q.push(mp(sr,sc));
    vis[sr][sc]=1;
    dis[sr][sc]=0;

        while(!q.empty())
        {
            pair<int,int>  temp=q.front();
            q.pop();

                int ur=temp.first;
                int uc=temp.second;

                if(ur == dr && uc == dc) return dis[ur][uc];

                    for(int i=0; i<8; i++)
                    {
                        int tr=ur+dir_r_8[i];
                        int tc=uc+dir_c_8[i];

                            if(tr>=0 && tr<n && tc>=0 && tc<m)
                            {
                                if(!vis[tr][tc])
                                {
                                    vis[tr][tc]=1;
                                    dis[tr][tc]=dis[ur][uc]+1;
                                    q.push(mp(tr,tc));
                                }
                            }
                    }
        }
}

int dp[16][1<<16],lim,len;

int bitmask(int i,int mask)
{
    if(mask == lim) return arr[i][len];
    if(dp[i][mask]!=-1) return dp[i][mask];

        int ans=INT_MAX;

        for(int j=0; j<len; j++)
        {
            if(!(mask & (1<<j)))
            {
                ans=min(ans,bitmask(j,(mask | 1<<j))+arr[i][j]);
            }
        }//cout<<ans<<endl;
    return dp[i][mask]=ans;
}

int main()
{
    int tc,ans,s,e;
        sf(tc);

            loop1(tt,tc)
            {

                vv.clear();
                scanf("%d %d", &n,&m);

                    for(int i=0; i<n; i++)
                    {
                        cin>> str[i];

                            for(int j=0; j<m; j++)
                            {
                                if(str[i][j] == 'x'){s=i;e=j;}
                                else if(str[i][j] == 'g') vv.pb(mp(i,j));
                            }
                    }


                            len=vv.size();


                            if(len == 0) ans=0;
                            else
                            {
                                vv.pb(mp(s,e));

                                    for(int i=0; i<=len; i++)
                                    {
                                        int sr=vv[i].first,sc=vv[i].second;

                                        for(int j=i+1; j<=len; j++)
                                        {
                                            memset(vis,0,sizeof(vis));
                                            int dr=vv[j].first,dc=vv[j].second;
                                            arr[j][i]=arr[i][j]=bfs(sr,sc,dr,dc);
                                            //cout<<i<<" "<<j<<" "<<arr[i][j]<<endl;
                                        }
                                    }
                                    lim = ((1<<len)-1);

                                    memset(dp,-1,sizeof(dp));
                                    ans=bitmask(len,0);
                                    //cout<<ans<<endl;
                            }
                   pf("Case %d: %d\n",tt,ans);
            }
    return 0;
}