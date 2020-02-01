#include <bits/stdc++.h>
#include <ext/rope>

using namespace __gnu_cxx;
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
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define bitOff(N,in)            (N&(~(1LL<<(in))))
#define bitOn(N,in)             (N|(1LL<<(in)))
#define ull                     unsigned long long
#define eps                     .000000001

#define mx                      2000005
#define mod                     998244353

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";if(!res) curstr += ((char)res + '0');while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

int main()
{
    int tc,n,k,val;

    scanf("%d", &tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%d %d", &n,&k);

        vector <int> zero,pos,neg;

        for(int i=1; i<=n; i++)
        {
            scanf("%d", &val);
            if(!val) zero.pb(0);
            else if(val>0) pos.pb(val);
            else neg.pb(val);
        }

        sort all(neg);//for(int i=0; i<neg.size(); i++) cout<<" "<<neg[i]; cout<<endl;


        for(int i=0; i<neg.size() && k; i++)
        {
            if(k)
            {
                neg[i] *= -1;//out(neg[i]);
                pos.pb(neg[i]);
                neg[i] = 0;
                k--;
            }
        }

        if(zero.size()) k = 0;

        sort all(pos);
        if(k>0)
        {
            if(k%2 == 1) pos[0] *= -1;
            //else if(k%1 == 0 && neg.size()) neg[neg.size()-1] *= -1;
        }
        int res = 0;
        for(int i=0; i<neg.size(); i++) res += neg[i];
        for(int i=0; i<pos.size(); i++) res += pos[i];

        printf("%d\n", res);
    }

    return 0;
}