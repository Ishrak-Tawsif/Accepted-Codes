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
#define inf                     1e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

int n,m,cnt=0;
int grid[1003][1003];
vector <pair<int,int> > vv[5];

void K(int u,int v)
{
    int temp1,temp2;

        temp1=u+1;temp2=v+2;
        if(temp1<=n && temp2<=m){
            if(grid[temp1][temp2]!=4 || grid[temp1][temp2]!=3 || grid[temp1][temp2]!=2)grid[temp1][temp2]=1;
        }


        temp1=u-1;temp2=v-2;
        if(temp1>0 && temp2>0){
            if(grid[temp1][temp2]!=4 || grid[temp1][temp2]!=3 || grid[temp1][temp2]!=2)grid[temp1][temp2]=1;
        }

        temp1=u+1;temp2=v-2;
        if(temp1<=n && temp2>0){
            if(grid[temp1][temp2]!=4 || grid[temp1][temp2]!=3 || grid[temp1][temp2]!=2)grid[temp1][temp2]=1;
        }

        temp1=u+2;temp2=v+1;
        if(temp1>0 && temp2>0){
            if(grid[temp1][temp2]!=4 || grid[temp1][temp2]!=3 || grid[temp1][temp2]!=2)grid[temp1][temp2]=1;
        }

        temp1=u+2;temp2=v-1;
        if(temp1>0 && temp2>0){
            if(grid[temp1][temp2]!=4 || grid[temp1][temp2]!=3 || grid[temp1][temp2]!=2)grid[temp1][temp2]=1;
        }

        temp1=u-2;temp2=v-1;
        if(temp1>0 && temp2>0){
            if(grid[temp1][temp2]!=4 || grid[temp1][temp2]!=3 || grid[temp1][temp2]!=2)grid[temp1][temp2]=1;
        }

        temp1=u-2;temp2=v+1;
        if(temp1>0 && temp2>0){
            if(grid[temp1][temp2]!=4 || grid[temp1][temp2]!=3 || grid[temp1][temp2]!=2)grid[temp1][temp2]=1;
        }

        temp1=u-1;temp2=v+2;
        if(temp1>0 && temp2<=m){
            if(grid[temp1][temp2]!=4 || grid[temp1][temp2]!=3 || grid[temp1][temp2]!=2)grid[temp1][temp2]=1;
        }
}

void Q(int u,int v)
{
    for(int i=v+1;i<=m;i++){
        if(grid[u][i]==3 || grid[u][i]==4 || grid[u][i]==2)break ;
        grid[u][i]=1;
    }

    for(int i=u+1;i<=n;i++){
        if(grid[i][v]==3 || grid[i][v]==4 || grid[i][v]==2)break ;
        grid[i][v]=1;
    }

    for(int i=v-1;i>0;i--){
        if(grid[u][i]==3 || grid[u][i]==4 || grid[u][i]==2)break ;
        grid[u][i]=1;
    }

    for(int i=u-1;i>0;i--){
        if(grid[i][v]==3 || grid[i][v]==4 || grid[i][v]==2)break ;
        grid[i][v]=1;
    }

    for(int i=u+1,j=v+1;i<=n && j<=m;i++,j++){
        if(grid[i][j]==3 || grid[i][j]==4  || grid[i][j]==2 )break ;
        grid[i][j]=1;
    }

    for(int i=u-1,j=v-1;i>0 && j>0;i--,j--){
        if(grid[i][j]==3 || grid[i][j]==4|| grid[i][j]==2)break ;
        grid[i][j]=1;
    }

    for(int i=u-1,j=v+1;i>0 && j<=m;i--,j++){
        if(grid[i][j]==3 || grid[i][j]==4 || grid[i][j]==2)break ;
        grid[i][j]=1;
    }

    for(int i=u+1,j=v-1;i<=n && j>0;i++,j--){
        if(grid[i][j]==3 || grid[i][j]==4 || grid[i][j]==2)break ;
        grid[i][j]=1;
    }
}

int main()
{//WRITE("in.txt");

    int temp,rr,cc,tt=0;
    while(~scanf("%d %d",&n,&m) && n && m)
    {
        mem(grid,0);
        for(int i=0; i<3; i++) vv[i].clear();


        for(int i=0; i<3; i++)
        {
            sf(temp);
            for(int j=0; j<temp; j++)
            {
                scanf("%d %d", &rr,&cc);
                vv[i].pb(mp(rr,cc));
                if(i == 0) grid[rr][cc] = 2;
                else if(i == 1) grid[rr][cc] = 3;
                else grid[rr][cc] = 4;
            }
        }

        for(int i=0; i<vv[0].size(); i++)
        {
            Q(vv[0][i].first,vv[0][i].second);
        }

        for(int i=0; i<vv[1].size(); i++)
        {
            K(vv[1][i].first,vv[1][i].second);
        }

        cnt=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++) if(!grid[i][j]) cnt++;
        }

        pf("Board %d has %d safe squares.\n", ++tt,cnt);
    }

    return 0;
}