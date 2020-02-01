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


int dx[8] = {1,-1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};

int dirr[] = {-1,-1,0,0,1,1};
int dirc[] = {0,1,-1,1,-1,0};

//int n,ar[200005],ar2[200005],dp[10005][3];

//int nod,vis[1003],cnt;
//vector <int> graph[1003];

string str[10005],ans;
int l[10005],h[10005];



/*
    1/k = 1/x + 1/y
   => 1/k = (x+y)/xy
   => kx + ky = xy
   => k + (ky/x) = y
   => k = y-(ky/x)
   => k = (xy-ky)/x
   => k = (y(x-k))/x
   => kx = y(x-k)
   => y = (kx/(x-k))

*/


int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
	int k;

	while(~sf(k))
    {

        vector <pair<int,int> > ans;

        for(int i=k+1; i<=2*k; i++)
        {
            if((k*i)%(i-k) == 0)
            {
                int temp = (k*i)/(i-k);
                ans.pb(mp(i,temp));
            }
        }

        pf("%d\n", ans.size());

        for(int i=0; i<ans.size(); i++)
        {
            pf("1/%d = 1/%d + 1/%d\n",k,ans[i].second,ans[i].first);
        }
    }
	return 0;
}