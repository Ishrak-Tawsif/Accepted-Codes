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

vector <pair<int,int>> vv;

int main()
{
    int n,m,s,t,u,v;

    while(scanf("%d %d", &n,&m))
    {
        if(!n && !m) break;

        vv.clear();

        for(int i=0; i<n; i++)
        {
            scanf("%d %d %d %d", &s,&t,&u,&v);
            vv.pb(mp(u,u+v-1));
        }

        int cnt;
        for(int i=1; i<=m; i++)
        {
            cnt=0;
            scanf("%d %d", &u,&v);
            v = (u+v)-1;
            for(int i=0; i<n; i++)
            {
                if(vv[i].first>=u && vv[i].first<=v) cnt++;
                else if(vv[i].second>=u && vv[i].second<=v) cnt++;
                else if(u>=vv[i].first && u<=vv[i].second) cnt++;
                else if(v>=vv[i].first && v<=vv[i].second) cnt++;
            }
            pf("%d\n", cnt);
        }
    }
    return 0;
}