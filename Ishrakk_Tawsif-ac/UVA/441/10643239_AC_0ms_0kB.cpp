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

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
	int n,fl=0;

	while(sf(n) == 1 && n)
    {

        int ar[n+3];

        if(fl) pf("\n");
        else fl=1;

        for(int i=0; i<n; i++) sf(ar[i]);

        for(int i=0; i<n-5; i++)
        {
            for(int j=i+1; j<n-4; j++)
            {
                for(int k=j+1; k<n-3; k++)
                {
                    for(int l=k+1; l<n-2; l++)
                    {
                        for(int m=l+1; m<n-1; m++)
                        {
                            for(int o=m+1; o<n; o++)
                            {
                                pf("%d %d %d %d %d %d\n", ar[i],ar[j],ar[k],ar[l],ar[m],ar[o]);
                            }
                        }
                    }
                }
            }
        }
    }

	return 0;
}