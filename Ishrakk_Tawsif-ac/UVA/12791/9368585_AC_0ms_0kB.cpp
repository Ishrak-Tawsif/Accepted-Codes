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
    int tc,x,y,diff,len,temp;

        while(scanf("%d %d", &x,&y) == 2)
        {
            len = 1;
            int tempx = 0;
            int tempy = 0;

                while(1)
                {
                    diff = tempy - tempx;
                    if(diff>=x){pf("%d\n",len); break;}

                    tempx += x;
                    tempy += y;
                    len++;

                }
        }
    return 0;
}