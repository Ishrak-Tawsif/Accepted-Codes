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
#define mx                      1000005
#define mod                     1000000009
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

int vis[13],ar[13],l,havewalk;
vector <int> graph[13];


void backtrack(int node,int cost)
{
    if(cost == l+1)
    {
        pf("(%d", ar[0]+1);
        for(int i=1; i<cost; i++) pf(",%d", ar[i]+1);
        pf(")\n");
        havewalk = 1;
        return;
    }

    for(int i=0; i<graph[node].size(); i++)
    {
        int now = graph[node][i];//if(node == 0) cout<<"here "<<now<<endl;
        if(!vis[now])
        {
            vis[now] = 1;
            ar[cost] = now;
            backtrack(now,cost+1);
            vis[now] = 0;
        }
    }
}

int main()
{
    int n,fl = 0,temp;
    string str;

    while(~sf(n))
    {
        for(int i=0; i<13; i++) graph[i].clear();
        mem(vis,0);

        if(fl) pf("\n");

        if(n == -9999)
        {
            scanf("%d %d", &n,&l);
        }
        else sf(l);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                sf(temp);
                if(temp) graph[i].pb(j);
            }
        }

        fl = 1;
        havewalk = 0;

        ar[0] = 0;
        vis[0] = 1;
        backtrack(0,1);
        
        if(!havewalk) pf("no walk of length %d\n", l);
    }

    return 0;
}