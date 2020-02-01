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

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

ll arn[2005],arm[2005];
unordered_map <ll,ll> cnt,mark;
vector <ll> vv;

int main()
{
    ll n,m,ans=0,res=0;
    cin>>n >>m;
    for(int i=0; i<n; i++) cin>> arn[i];
    for(int i=0; i<m; i++) cin>> arm[i];

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            ll temp = arm[i] - arn[j];
            if(temp>0)
            {
                if(!mark[temp]) mark[temp] = 1,vv.pb(temp);
                cnt[temp] ++;
            }
        }
    }
        sort(vv.begin(),vv.end());
        for(int i=0; i<vv.size(); i++)
        {
            if(ans<cnt[vv[i]])
            {
                ans = cnt[vv[i]];
                res = vv[i];
            }
        }
    cout<<res<<endl;
    return 0;
}