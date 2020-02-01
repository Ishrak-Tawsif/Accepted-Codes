#include<bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

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
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007

int n;
ll ar[100005];

int calc(int s,int e,int d)
{
    int cnt = 0;
    for(int i=s; i<=e; i++) if(i%d == 0) cnt++;
    return cnt;
}

int b_search(ll val)
{
    int st = 0,en = (n-1),mid,ans = -1;

    while(st<=en)
    {
        mid = (st + en)>> 1;
        if(ar[mid]>= val) ans = mid,en = mid-1;
        else st = mid+1;
    }
    return ans;
}

int b_search2(ll val)
{///high
    int st = 0,en = (n-1),mid,ans = -1;

    while(st<=en)
    {
        mid = (st + en)>> 1;
        if(ar[mid]<=val) ans = mid,st = mid + 1;
        else en = mid - 1;
    }
    return ans;
}


int main()
{

    //int s,e,d;
    //while(cin>>s >>e>> d) cout<<calc(s,e,d)<<endl;

    ll k;
    ll x;

    sf(n);
    scanf("%lld %lld", &x,&k);

    for(int i=0; i<n; i++) scanf("%lld", &ar[i]);
    sort(ar, ar+n);
    ll ans,res = 0;
    for(int i=0; i<n; i++)
    {
        ll low,high;
        ans = 0;

        if(ar[i]%x == 0)
        {
            if(k == 0) continue;
            if(k == 1) low = ar[i];
            else low = (ar[i] + (x*(k-1)));

            high = low + (x-1);
        }
        else
        {
            ll first = (ar[i]/x);
            first = (first + 1) * x;

            if(k == 0) low = ar[i],high = first-1;
            else if(k == 1) low = first,high = low + (x-1);
            else
            {
                low = (first + (x*(k-1)));
                high = low + (x-1);
            }
        }
//cout<<low<<" "<<high<<endl;
        ll temp = b_search2(high);
        ll temp2 = b_search(low);//cout<<temp<<" |||| "<<temp2<<endl;
        ans += (temp-temp2);
        if(temp == -1 || temp2 == -1) ans = 0;
        else ans++;

        res += ans;
    }
    pf("%lld\n", res);

    return 0;
}