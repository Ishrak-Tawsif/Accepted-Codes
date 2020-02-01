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
#define intinf                  7e18
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

vector <int> lc,nin;

int main()
{
    int tc,n,s,d,ans;
    char ch;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        sf(n);

        nin.clear();
        lc.clear();


        for(int i=0; i<n; i++)
        {
            scanf("%d %d %c", &d,&s,&ch);
            if(ch == 'c' && s == 1) lc.pb(d);
            if(ch == 'i' && s == 0) nin.pb(d);

        }

        sort(lc.begin(),lc.end());
        sort(nin.begin(),nin.end());

        ans = 0;

        int j=0;

            for(int i=0; i<nin.size(); i++)
            {
                int cur = nin[i];
                while(lc[j]<=cur && j<lc.size()) j++;
                ans = ans + (lc.size()-j);
            }

        pf("%d\n" ,ans);
    }

    return 0;
}