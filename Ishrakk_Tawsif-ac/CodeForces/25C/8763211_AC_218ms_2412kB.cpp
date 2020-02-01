#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 100005
#define ll long long int
#define mp make_pair
#define mod 100000007

int dir_r_8[]={-1,-1,-1,0,0,1,1,1};
int dir_c_8[]={-1,0,1,-1,1,-1,0,1};
int dir_r_4[]={-1,1,0,0};
int dir_c_4[]={0,0,-1,1};

/*int n,wei[mx],vis[mx],cnt,k;
ll sum;
vector <int> graph[mx];*/

/*void bfs(int s)
{
    queue <int> q;
    vis[s]=cnt;
    sum = (ll) ( (ll) wei[s] * (ll) k);
    q.push(s);
    q.push(k-1);

        while(!q.empty())
        {
            int u = q.front(); q.pop();
            int kk = q.front(); q.pop();

                int v = graph[u][0];

                    if(u == 1 || kk == 0) return;

                    if(vis[v]!=cnt)
                    {
                        vis[v]=cnt;
                        sum += (ll) ((ll)wei[v] * (ll) kk);//cout<<v<<" " << wei[v] <<" " << kk << " " <<sum<<endl;
                        q.push(v);
                        q.push(kk-1);
                    }
        }
}*/

int n,wei[301][301];
ll sum;

int main()
{
    sf(n);

        loop1(i,n)
        {
            loop1(j,n) sf(wei[i][j]);
        }

        int query,u,v,w;

            sf(query);

            loop1(i,n)
            {
                loop1(j,n)
                {
                    loop1(k,n) wei[j][k]=min(wei[j][k],wei[j][i]+wei[i][k]);
                }
            }

                loop(i,query)
                {
                    scanf("%d %d %d",&u,&v,&w);

                        //loop1(i,n){loop1(j,n){wei2[i][j]=wei[i][j];}}

                        if(w<wei[u][v])wei[u][v]=wei[v][u]=w;
                        //{
                            //for(int i=1; i<=n; i++)
                            //{
                                for(int j=1; j<=n; j++)
                                {
                                    for(int k=j+1; k<=n; k++)
                                    {
                                        //cout << j << " " << k << " " << wei[j][k] << " " << wei[j][u] << " " << wei[u][v] << " " <<wei[v][k] << endl;
                                        wei[j][k] = wei[k][j] = min(wei[j][k],wei[j][u]+wei[u][v]+wei[v][k]);
                                        wei[j][k] = wei[k][j] = min(wei[j][k],wei[j][v]+wei[v][u]+wei[u][k]);
                                    }
                                }
                                /*for(int j=1; j<=n; j++)
                                {
                                    for(int k=j+1; k<=n; k++)
                                    {
                                        //cout << j << " " << k << " " << wei[j][k] << " " << wei[j][u] << " " << wei[u][v] << " " <<wei[v][k] << endl;
                                        wei[j][k] = min(wei[j][k],wei[j][u]/*+wei[u][v]*///+//wei[u][k]);
                                        //wei[j][k] = min(wei[j][k],wei[j][v]+wei[v][u]+wei[u][k]);
                                    //}
                                //}*/
                            //}

                            sum=0;
                            for(int i=1; i<=n; i++)
                            {
                                for(int j=i+1; j<=n; j++){sum += (ll) wei[i][j]; /*cout<<wei[i][j]<<endl;*/}
                            }
                        //}
                            pf("%lld\n",sum);
                }
    return 0;
}