#include <bits/stdc++.h>
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
#define loop1(var,start,till)   for(int var=start; var<=till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define all(a)                  (a.begin(),a.end())
#define Unique_(a)              sort(all(a));a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define ull                     unsigned long long
#define eps                     .000000001

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";if(!res) curstr += ((char)res + '0');while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

ll ar[200005],ans[200005];

ll calc(ll val,ll now,ll m)
{
    if(val<=now) return now - val;
    else return (m+now-val);
}

int main()
{
//out(calc(3,3,5));
    int n,m;

    scanf("%d %d", &n,&m);

    for(int i=1; i<=n; i++) sf(ar[i]);

    vector <pair<ll,int> > vv;
    for(int i=1; i<=n; i++) vv.pb(mp(ar[i]%m,i));
    sort all(vv);

    int st=0,en=vv.size()-1;
    ll totcst = 0;

    for(int i=0; i<m; i++)
    {
        int cnt = n/m;
        while(cnt--)
        {//cout<<st<<" "<<en<<endl;
            if(vv[st].first == i) ans[vv[st].second] = ar[vv[st].second],st++;
            else if(vv[en].first == i) ans[vv[en].second] = ar[vv[en].second],en--;
            else
            {
                ll fs = vv[st].first;
                ll sn = vv[en].first;

                fs = calc(fs,i,m);
                sn = calc(sn,i,m);

                if(fs<sn)
                {
                    totcst += fs;
                    ans[vv[st].second] = ar[vv[st].second]+fs;
                    st++;
                }
                else totcst += sn,ans[vv[en].second] = ar[vv[en].second]+sn,en--;
            }
        }
    }

    pf("%lld\n", totcst);
    for(int i=1; i<=n; i++)
    {
        if(i == 1) pf("%d", ans[i]);
        else pf(" %d", ans[i]);
    }

    return 0;
}