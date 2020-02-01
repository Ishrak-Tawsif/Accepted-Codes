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
#define ll                      unsigned long long int
#define mx                      5005
#define mod                     1000007
#define intinf                  2100000000
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())

int call(int ahr,int mn,int hr,int mnt,int cst)
{

    int armin = (ahr*60)+mn;
    int minute = (hr*60)+mnt;

        if(armin>minute)
        {
            minute = minute + (24*60);
        }
    return (minute-armin)+cst;
}

int main()
{
    int tc,n,hr,mn,ahr,amn,cst,min_;

        sf(tc);

            loop(tt,1,tc+1)
            {
                min_ = intinf;
                sf(n);
                scanf("%d:%d", &ahr,&amn);

                    loop(i,0,n)
                    {
                        scanf("%d:%d %d", &hr,&mn,&cst);
                        min_ = min(min_,call(ahr,amn,hr,mn,cst));
                    }
                pf("Case %d: %d\n",tt,min_);
            }
    return 0;
}