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
#define mx                      1000000+25
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

bitset <mx> isprime;
vector <int> prime;
int vis[1000005],ar[1000005],par[1000005],mark[2000005];
unordered_map<int,int>id;

void sieve()
{
    prime.pb(2);
    isprime[0] = isprime[1] = 1;

    for(int i=3; i*i<mx; i++)
    {
       if(!isprime[i]) for(int j=i*i; j<mx; j+=i) isprime[j] = 1;
    }

    for(int i=3; i<mx; i+=2) if(!isprime[i]) prime.pb(i);
}

int findpar(int p)
{
    if(par[p] == p) return p;
    else return par[p] = findpar(par[p]);
}

int main()
{//WRITE("in.txt");
    sieve();
//out(prime[prime.size()-1]);
    int tc,max_;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        int n;

        sf(n);

        max_ = -1;
        mem(vis,0);
        mem(mark,0);
        id.clear();
        int curid = 0;

        for(int i=1; i<=n; i++)
        {
            sf(ar[i]);
            mark[ar[i]] = 1;
            max_ = max(max_,ar[i]);
            if(!id[ar[i]]) id[ar[i]] = ++curid;
            //par[ar[i]] = ar[i];
        }

        int len = prime.size();


        for(int i=0; i<len; i++) if(prime[i]<=max_)if(!id[prime[i]]) id[prime[i]] = ++curid;
        for(int i=1; i<=curid; i++) par[i] = i;
        //for(int i=1; i<=n; i++) cout<<ar[i]<<" "<<id[ar[i]]<<endl;
        for(int i=0; i<len; i++)
        {//out(prime[i]);
            if(prime[i]>max_) break;
            int paru,parv;
            paru = findpar(id[prime[i]]);
            for(int j=1; ; j++)
            {
                int v = (j*prime[i]);
                if(v>max_) break;//out(v);
                //int parv = findpar(v);
                if(mark[v])
                {
                    parv= findpar(id[v]);
//cout<<paru<<" "<<parv<<" "<<v<<endl;
                    if(paru != parv)
                    {
                        par[parv] = paru;
                    }
                }
            }
        }
        int cnt = 0;
        for(int i=1; i<=n; i++)
        {
            if(ar[i] == 1) {cnt++;continue;}
            int temp = findpar(id[ar[i]]);
            if(!vis[temp]) cnt++,vis[temp] = 1;
        }

        casepf(tt);
        pf("%d\n", cnt);
    }

    return 0;
}