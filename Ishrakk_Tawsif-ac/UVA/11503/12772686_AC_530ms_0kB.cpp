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
#define mx                      200005
#define mod                     1000000007
#define pi                      acos(-1)
#define eps                     1e-7

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

unordered_map <string,int> id;
int par[3*100005],frnd[3*100005];

int  findpar(int p)
{
    if(par[p] == p) return p;
    return par[p] = findpar(par[p]);
}

int main()
{//WRITE("in.txt");
    string a,b;
    int tc,curid,n,cnt,koyta;

    sf(tc);

    while(tc--)
    {
        curid = cnt = 0;
        id.clear();

        sf(n);
        for(int i=1; i<=((2*n)+5); i++) par[i] = i,frnd[i] = 1;
        for(int i=1; i<=n; i++)
        {
            cin >>a >>b;
            koyta=0;

            if(!id[a]) id[a] = ++curid,koyta++;
            if(!id[b]) id[b] = ++curid,koyta++;

            int ida = id[a];
            int idb = id[b];

            int para = findpar(ida);
            int parb = findpar(idb);

            if(para != parb)
            {
                frnd[parb] += (frnd[para]);
                frnd[para] = frnd[parb];
                par[para] = parb;
                cnt = (frnd[parb]);
            }
            else cnt = frnd[para];

            pf("%d\n",cnt);
        }
    }
    return 0;
}