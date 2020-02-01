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
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

int n;

struct ST
{
    int x,y;
    bool operator <(const ST & nn) const
    {
        if(y == nn.y) return abs(x)<abs(nn.x);
        return abs(y)<abs(nn.y);
    }
};
vector <ST> vv;

int main()
{
    sf(n);
    ST get;
    int cnt = 0;

    for(int i=0; i<n; i++)
    {
        scanf("%d %d", &get.x,&get.y);
        vv.pb(get);
        if(vv[i].x && vv[i].y)
        {
            cnt += 6;
        }
        else cnt += 4;
    }

    pf("%d\n", cnt);
    sort all(vv);
    for(int i=0; i<vv.size(); i++)
    {
        int xx = vv[i].x;
        int yy = vv[i].y;

        if(xx)
        {
            if(xx>0)
            {
                pf("1 %d R\n",xx);
            }
            else
            {
                pf("1 %d L\n",abs(xx));
            }
        }
        if(yy)
        {
            if(yy>0)
            {
                pf("1 %d U\n",yy);
            }
            else
            {
                pf("1 %d D\n",abs(yy));
            }
        }
        pf("2\n");
        if(yy)
        {
            if(yy>0)
            {
                pf("1 %d D\n",yy);
            }
            else
            {
                pf("1 %d U\n",abs(yy));
            }
        }
        if(xx)
        {
            if(xx>0)
            {
                 pf("1 %d L\n",xx);
            }
            else
            {
                 pf("1 %d R\n",abs(xx));
            }
        }
        pf("3\n");
    }

    return 0;
}