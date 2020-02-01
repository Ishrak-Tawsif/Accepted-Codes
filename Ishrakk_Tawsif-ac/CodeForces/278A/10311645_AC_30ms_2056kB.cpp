#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<=till; var++)
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


int dr8[]={-1,-1,0,1,1,1,0,-1};
int dc8[]={0,1,1,1,0,-1,-1,-1};


string str;
int arr[107];

int main()
{
    int n,s,d,temp;

    sf(n);

    for(int i=2; i<=n+1; i++) {sf(temp); arr[i] = arr[i-1] + temp;}

    sf(s);
    sf(d);

    if(d<s)
    {
        int sss = s;
        s = d;
        d = sss;
    }

    int diff = arr[d] - arr[s];//cout<<arr[n+1]<<endl;

    diff = min(diff,(arr[n+1]-diff));

    pf("%d\n", diff);

    return 0;
}