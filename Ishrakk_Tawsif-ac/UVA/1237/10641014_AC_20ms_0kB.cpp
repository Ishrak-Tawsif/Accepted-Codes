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
	int tc,n;

	sf(tc);

	for(int tt=1; tt<=tc; tt++)
    {
        sf(n);

        for(int i=0; i<n; i++)
        {
            cin>> str[i];
            scanf("%d %d", &l[i], &h[i]);
        }

        int q,pri,cnt;
        sf(q);

        while(q--)
        {
            scanf("%d", &pri);
            cnt=0;

                for(int i=0; i<n; i++)
                {
                    if(l[i]<=pri && pri<=h[i])
                    {
                        cnt++;
                        ans = str[i];
                        if(cnt>1) break;
                    }
                }//cout<<tc<<".."<<endl;
            if(cnt == 1) cout<<ans<<endl;
            else pf("UNDETERMINED\n");
        }

        if(tt != tc) pf("\n");
    }
	return 0;
}