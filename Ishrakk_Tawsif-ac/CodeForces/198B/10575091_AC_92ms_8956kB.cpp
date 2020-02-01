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
#define intinf                  1e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007


int dx[8] = {1,-1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};

int dirr[] = {-1,-1,0,0,1,1};
int dirc[] = {0,1,-1,1,-1,0};

int n,k,ispos=0,vis[2][200005],diss[2][100005];
string str[3];

void dfs(int wall,int stage,int dis)
{
    //vis[wall][stage] = 1;
//cout<<wall<<" "<<stage<<endl;
//cout<<wall << " " << stage << " " << dis <<" " << str[wall][stage] << " " << vis[wall][stage]<< endl;
     if(dis>=stage) return;

     if(stage>=n){ispos=1; return;}

     if(str[wall][stage] == 'X') return;
     if(vis[wall][stage] /*&& diss[wall][stage]<dis) || (ispos)*/) return;
     vis[wall][stage] = 1;//cout<<wall << " .......... " << stage << " " << dis << endl;
     diss[wall][stage] = dis;
     //if(stage>=n){ispos = 1; return;}

     /*if(!vis[wall][stage+1])*/
     /*if(!vis[1-wall][stage+k])*/
     if(stage-1>=0)
     {
         /*if(!vis[wall][stage-1])*/dfs(wall,stage-1,dis+1);
     }
     dfs(1-wall,stage+k,dis+1);
     dfs(wall,stage+1,dis+1);
}

int main()
{
    scanf("%d %d", &n,&k);
    for(int i=0; i<100005; i++)diss[0][i] = diss[1][i] = intinf;//cout<<diss[0][0]<<endl;
    cin>> str[0];
    cin>> str[1];

    //mem(dis,-1);//cout<<dis[0][0]<<endl;
    ispos=0;
    dfs(0,0,-1);

    (ispos==1)? pf("YES\n") : pf("NO\n");

    return 0;
}

/*
13 2
---X---X--X-X
--X---X-X--X-
*/