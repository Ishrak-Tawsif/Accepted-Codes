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

ll ncr[1005][1005];

void genncr()
{
    for(int i=1; i<1005; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(j == 1) ncr[i][j] = i;
            else if(j == 0) ncr[i][j] = 1;
            else ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
        }
    }
}

int main()
{
    int n,k;
    /*while(1)
    {
        res = 0;
        sf(n); sf(k);
        int ar[n+3];

        for(int i=1; i<=n; i++) ar[i-1] = i;

        int koyta[11];
        mem(koyta,0);

        do
        {
            int cnt = 0;
            for(int i=0; i<n; i++) if(ar[i] == i+1) cnt++;
            if(cnt >= (n-k)) {res++;
            koyta[cnt] ++;}
        }while(next_permutation(ar, ar+n));
        for(int i=0; i<11; i++) if(koyta[i]) cout<<i<<" "<<koyta[i]<<endl;
        out(res);
    }*/

    genncr();
    cin>> n>> k;

    ll res = 0;

    ll ans[5];
    ans[1] = 1;
    ans[2] = 1;
    ans[3] = 2;
    ans[4] = 9;
    int st = (n-k);
    for(int i = st; i<=(n-2) && k>=1; i++,k--)
    {
        res += ncr[n][i]*ans[k];
    }

    out(res+1);
    return 0;
}