#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case #%d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

vector <pair<int,int> >vv;
int n;
ll totalorange,totalapple;
bool ar[1000010];

int call()
{
    //int ar[n+3];
    //mem(ar,0);

    int cnt = 100;
    srand(time(0));

    int m = (2*n)-1;
    for(int i=0; i<m; i++) ar[i] = 0;
    for(int i=0; i<n; i++) ar[m-i-1] = 1;

    while(1)
    {
        random_shuffle(ar,ar+m);

        ll org = 0,app = 0;
        for(int i=0; i<2*n-1; i++)
        {
            if(ar[i])
            {
                app += (ll) vv[i].first;
                org += (ll) vv[i].second;
            }
        }
        if(org*2>=(totalorange) && app*2>=(totalapple))
        {
            pf("YES\n");
            int flag = 0;
            for(int i=0; i<2*n-1; i++)
            {
                if(ar[i] && !flag) pf("%d", i+1),flag=1;
                else if(ar[i]) pf(" %d", i+1);
            }pf("\n");
            break;
        }
    }
    //pf("NO\n");
    return 0;
}

int main()
{
    int tc,u,v;

    sf(tc);

    while(tc--)
    {
        sf(n);
        totalapple = 0;
        totalorange = 0;
        vv.clear();
        for(int i=0; i<(2*n-1); i++)
        {
            scanf("%d %d", &u,&v);
            vv.pb(mp(u,v));
            totalorange += (ll) v;
            totalapple += (ll)u;
        }

        int fl = 0;
        fl = call();
        //fl? pf("YES\n") : pf("NO\n");
    }
    return 0;
}