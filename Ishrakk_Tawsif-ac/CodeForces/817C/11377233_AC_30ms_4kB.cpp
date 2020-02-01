 #include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case #%d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     1e9
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      1000005
#define mod                     1000000007
#define endval                  1e-9

ll n,m;

bool check(ll val)
{
    ll temp = val,sum=0,cur;

        while(temp != 0)
        {
            sum += temp%10;
            temp /= 10;
        }
        cur = abs(sum-val);
        //cout<<cur<<" "<<val<<endl;
    return (cur>=m);
}

int main()
{
    scanf("%lld %lld", &n,&m);

    ll high,low=-1;

    ll st = 1,en = n,mid;

    /*while(st<=en)
    {
        mid = (st+en)/2;
        if(!check(mid)) high = mid,st = mid+1;
        else en = mid-1;
    }*/

    st = 0,en = n;

    while(st<=en)
    {
        mid = (st+en)/2;
        if(check(mid)) low = mid,en = mid-1;
        else st = mid+1;
    }

    low == -1? pf("0\n") : pf("%lld",(n-low)+1);

    return 0;
}