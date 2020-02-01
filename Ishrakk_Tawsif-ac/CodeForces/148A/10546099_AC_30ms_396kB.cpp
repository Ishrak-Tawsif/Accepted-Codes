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
#define mod                     100000007


int dr8[]={-1,-1,0,1,1,1,0,-1};
int dc8[]={0,1,1,1,0,-1,-1,-1};

int tr[100005];

int main()
{
    int k,l,m,n,tot,cnt=0;

    scanf("%d %d %d %d %d", &k,&l,&m,&n,&tot);

    for(int i=k; i<=tot; i+=k)
        if(tr[i] == 0){tr[i]=1; cnt++;}


    for(int i=l; i<=tot; i+=l)
        if(tr[i] == 0){tr[i]=1; cnt++;}

    for(int i=m; i<=tot; i+=m)
        if(tr[i] == 0){tr[i]=1; cnt++;}

    for(int i=n; i<=tot; i+=n)
        if(tr[i] == 0){tr[i]=1; cnt++;}


    pf("%d\n", cnt);

    return 0;
}