#include<bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

/*#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
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
#define all(a)                  (a.begin(),a.end())
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      1000005
#define mod                     1000000009

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

ll n,m;
ll ar[37],ina,inb,half;
vector <ll> a,b;

void call1(int pos,ll sum)
{//out(1);
    if(pos == half) {a.pb(sum%m); return;}

    call1(pos+1,(sum+ar[pos])%m);
    call1(pos+1,sum%m);
}

void call2(int pos,ll sum)
{//out(2);
    if(pos == n) {b.pb(sum%m);return;}

    call2(pos+1,(sum+ar[pos])%m);
    call2(pos+1,sum%m);
}

int bsearch(ll val,int en)
{//out(val);
    int st = 0,mid;
    int ans=-1;

    while(st<en)
    {
        mid = (st+en)/2;
//out(mid);
        if(b[mid]<=val)
        {//cout<<val<<" ... "<<b[mid]<<endl;
            ans = mid;
            st = mid+1;
        }
        else en = mid-1;
    }
    return ans;
}

int main()
{
    cin>> n>> m;

    for(int i=0; i<n; i++) cin>> ar[i];

    ina = -1;
    inb = -1;

    if(n == 1) out(ar[0]%m);
    else
    {
        half = (n/2);
        call1(0,0);
        call2(half,0);

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        //for(int i=0; i<=ina; i++) cout<<" "<<a[i]; cout<<endl;
        //for(int i=0; i<=inb; i++) cout<<" "<<b[i]; cout<<endl;
        ll res = -1;//out(ina);
        for(int i=0; i<a.size(); i++)
        {//out(i);
            vector <ll> :: iterator it = lower_bound(b.begin(),b.end(),(m-a[i]));

            ll cur;
            if(it == b.begin()) it = b.end();
            //else cur = b[pos];//cout<<a[i]<<" "<<cur<<endl;

            it--;
            res = max(res,(a[i]+*it)%m);

            res%=m;
        }
        pf("%lld\n", res%m);
    }
    return 0;
}