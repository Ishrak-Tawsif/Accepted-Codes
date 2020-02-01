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
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007


int dx[8] = {1,-1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};

ll ar[100005];

int bsearch(int s,int e,ll sv)
{
    int mid,ans=-1;

    while(s<=e)
    {
        mid = (s+e)>>1;

        if(ar[mid] == sv) {ans=mid;e=mid-1;}
        else if(ar[mid]>sv)
        {
            e = mid-1;
        }
        else s = mid+1;
    }
    return ans;
}

int main()
{
    ll n, q;

    scanf("%lld %lld", &n,&q);

    for(int i=0; i<n; i++) scanf("%lld", &ar[i]);

    ll temp;
    while(q--)
    {
        scanf("%lld", &temp);
        int ind = bsearch(0,n-1,temp);
        pf("%d\n", ind);
    }

    return 0;
}