#include<bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

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
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      5000005
#define mod                     1000000007

map<string,int> mpp;

int main()
{
    int n;

    sf(n);

    if(n%2==0) {pf("-1\n"); return 0;}

    int in  = 2;
    while(in--)
    {

        int fl = 0;
        for(int i=0; i<n; i++)
        {
            if(!fl) {pf("%d", i); fl=1;}
            else pf(" %d",i);
        }pf("\n");
    }

    pf("0");
    for(int i=1; i<n; i++) pf(" %d", (i+i)%n);
    pf("\n");
    return 0;
}