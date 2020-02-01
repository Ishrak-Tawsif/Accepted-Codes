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
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007


//int dx[8] = {1,-1,0,0,-1,-1,1,1};
//int dy[8] = {0,0,-1,1,-1,1,-1,1};

int dirr[] = {-1,-1,0,0,1,1};
int dirc[] = {0,1,-1,1,-1,0};

//int n,ar[200005],ar2[200005],dp[10005][3];

//int nod,vis[1003],cnt;
//vector <int> graph[1003];

int dx[] = {-1,-1,0,0,1,1};
int dy[] = {-1,0,-1,1,0,1};

int n,vis[203][203],isblack=intinf,iswhite=intinf,dis[203][203],temp;
string str[203];

void dfs(int sr,int sc,char col)
{
    vis[sr][sc] = 1;
//cout<<sr<<" " << sc << " " << dis[sr][sc]<<endl;

    if(sr == (n-1) && col == 'b' && str[sr][sc] == col)
        {temp = min(dis[sr][sc],temp);}
    if(sc==(n-1) && col == 'w' && str[sr][sc]==col)
        {temp = min(dis[sr][sc],temp);}

    for(int i=0; i<6; i++)
    {
        int tr = sr + dx[i];
        int tc = sc + dy[i];

//if(tr == (n-1) && col == 'b' && str[tr]){temp = min(dis[tr][tc],min(temp,dis[sr][sc]+1));cout<<"temp "<<temp<<" "<<tr<<" " <<tc<<endl;}
//if(tc == (n-1) && col == 'w'){temp = min(dis[tr][tc],min(temp,dis[sr][sc]+1));cout<<"temp "<<temp<<" "<<tr<<" " <<tc<<endl;}

            if(tr>=0 && tr<n && tc>=0 && tc<n)
            {
                if(!vis[tr][tc] && str[tr][tc]==col) {dis[tr][tc] = min(dis[tr][tc],dis[sr][sc]+1);dfs(tr,tc,col);}
            }
    }
    //return -1;
}


int main()
{
    //READ("in.txt");
    //WRITE("out.txt");

    int tt=0;
    while(sf(n)==1 && n)
    {//cout<<n<<endl;//cin.ignore();
        isblack = iswhite = intinf;
        for(int i=0; i<n; i++) cin>> str[i];
        for(int i=0; i<n; i++)
        {
            for(int i=0; i<n; i++)for(int j=0; j<n; j++){dis[i][j]=intinf; vis[i][j]=0;}
            temp = intinf;
            if(str[0][i] == 'b'){dis[0][i]=0;dfs(0,i,'b');isblack=min(temp,isblack);}
        }
        for(int i=0; i<n; i++)
        {
            for(int i=0; i<n; i++)for(int j=0; j<n; j++){dis[i][j]=intinf; vis[i][j]=0;}
            temp = intinf;
            if(str[i][0] == 'w'){dis[i][0]=0;dfs(i,0,'w');iswhite=min(temp,iswhite);}
        }//cout<<isblack<<" " << iswhite << endl;
        (iswhite>isblack)? pf("%d B\n",++tt) : pf("%d W\n",++tt);
    }

	return 0;
}