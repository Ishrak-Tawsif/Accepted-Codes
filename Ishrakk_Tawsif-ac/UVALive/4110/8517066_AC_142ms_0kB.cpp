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

struct order
{
    int u,v,w;

        bool operator < (const order &x) const
        {
            return w>x.w;
        }
};

vector <order> vv;
int path[10005];

int find_(int n)
{
    if(path[n]==n) return n;
    return path[n]=find_(path[n]);
}

int mst()
{
    int sum=0;

        for(int i=0; i<vv.size(); i++)
        {
            int u=vv[i].u;
            int v=vv[i].v;
            int w=vv[i].w;

                int a=find_(u);
                int b=find_(v);

                    if(a!=b)
                    {
                        path[a]=b;
                        sum+=w;
                    }
        }
    return sum;
}

int main()
{
    int tc,u,v,w,n,m,sum;
    order get;

        sf(tc);

            loop1(tt,tc)
            {
                sum=0;
                vv.clear();
                
                scanf("%d %d", &n,&m);
                loop(i,m){
                    scanf("%d %d %d", &get.u,&get.v,&get.w);
                    vv.pb(get);
                    sum += get.w;
                }

                sort(vv.begin(),vv.end());

                for(int i=1; i<=n; i++) path[i]=i;
                int res=mst();
                //cout<<res<<endl;
                pf("%d\n", sum-res);
            }
            int garbage;
            cin>>garbage;
            
    return 0;
}