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

double ncr(ll n,ll r)
{
    //if(r>n) return 0.0;
    //if(r == 0) return 0.0;

    if(n-r>r) r=n-r;
    double j=1,res=1.0;
    for(double i=r+1; i<=n; i++)
    {
        res = res*i;
        res/=j,j++;
    }
    return res;
}

int main()
{//cout<<ncr(4,2);
    ll n,m,h,temp,sum = 0,mydept;

    scanf("%lld %lld %lld", &n,&m,&h);

    for(int i=0; i<m; i++)
    {
        scanf("%lld", &temp);
        sum += temp;
        if(i == h-1) mydept = temp;
    }

    if(sum<n){pf("-1\n"); return 0;}

    sum--;
    n--;
    mydept--;

    double totteam = ncr(sum,n),jogfol=0.0;//cout<<n<<" "<<mydept<<endl;
    for(ll i=1; i<=min(mydept,n); i++)
    {//cout<<mydept<<" "<<i<<" "<<sum-mydept<<" "<<n-i<<endl;
        if(sum-mydept>=n-i) jogfol += (ncr(mydept,i) * ncr(sum-mydept,n-i));//out(jogfol);
    }//out(jogfol);
    jogfol = jogfol/totteam;
    pf("%.6f\n", jogfol);
    return 0;
}