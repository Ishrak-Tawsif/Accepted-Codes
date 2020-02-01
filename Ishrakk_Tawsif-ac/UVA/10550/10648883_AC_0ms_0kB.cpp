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


int main()
{
    //READ("in.txt");
    //WRITE("out.txt");


    int f1,f2,f3,f4,ans;

    while(~scanf("%d %d %d %d", &f1,&f2,&f3,&f4))
    {
        if(!f1 && !f2 && !f3 && !f4) break;
        ans = (360 * 3); ///1080

        int temp1 = f1 - f2; temp1 = (temp1>=0)? temp1 : (temp1+40);
        ans += (temp1*9);

        temp1 = f3 - f2; temp1 = (temp1>=0)? temp1 : (temp1+40);
        ans += (temp1 * 9);

        temp1 = f3 - f4; temp1 = (temp1>=0)? temp1 : (temp1+40);
        ans += (temp1 * 9);

        pf("%d\n", ans);
    }

	return 0;
}