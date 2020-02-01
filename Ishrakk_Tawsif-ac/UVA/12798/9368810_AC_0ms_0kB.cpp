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
#define mx                      5005
#define mod                     100000007
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())


int main()
{
    int n,m,cnt;

        while(scanf("%d %d", &n,&m) == 2)
        {
            cnt=0;
            int fl=1,temp;

                for(int i=0; i<n; i++)
                {
                    fl=1;
                    for(int i=0; i<m; i++)
                    {
                        sf(temp);
                        if(temp == 0) fl=0;
                    }
                    if(fl == 1) cnt++;
                }
                pf("%d\n", cnt);
        }
    return 0;
}