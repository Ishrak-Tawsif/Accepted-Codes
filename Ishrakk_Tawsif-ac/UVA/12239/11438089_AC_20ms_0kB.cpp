#define ONLINE_JUDGE 1
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
#define inf                     1e9
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      1000+5
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

int mark[105],ar[105];

int main()
{
    int n,b;

    while(scanf("%d %d", &n,&b))
    {

        if(!n && !b) break;
        for(int i=0; i<b; i++) sf(ar[i]);
        mem(mark,0);

        for(int i=0; i<b; i++)
        {
            for(int j=0; j<b; j++)
            {
                //if(i == j) continue;

                int temp = ar[i] - ar[j];
                if(temp<0) temp *= -1;

                mark[temp] = 1;
            }
        }
        int fl = 1;
        for(int i=0; i<=n; i++) if(!mark[i]) fl=0;

        fl? pf("Y\n") : pf("N\n");
    }
    return 0;
}