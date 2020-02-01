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
#define mx                      1123
#define mod                     1000000009
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define ull                     unsigned long long
#define eps                     .000000001

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/


int ar[7],ans[5],possible,vis[7],cnt;

void call(int ind,int val)
{//out(ind);
    if(ind == 5)
    {
        if(val == 23) possible = 1;
        return;
    }

    for(int i=0; i<5; i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            call(ind+1,val + ar[i]);
            call(ind+1,val - ar[i]);
            call(ind+1,val * ar[i]);
            vis[i] = 0;
        }
    }
}

int main()
{

    #ifndef ONLINE_JUDGE
    	clock_t TStart = clock();
        //READ("in.txt");
        //WRITE("out.txt");
    #endif

    while(scanf("%d %d %d %d %d", &ar[0],&ar[1],&ar[2],&ar[3],&ar[4]))
    {
        if(!ar[0]) break;
        possible = 0;
        for(int i=0; i<5; i++)
        {
            vis[i] = 1;
            call(1,ar[i]);
            vis[i] = 0;
        }
        possible? pf("Possible\n") : pf("Impossible\n");
    }

    #ifndef ONLINE_JUDGE
    	printf("\n>>Time taken: %.10fs\n", (double) (clock() - TStart) / CLOCKS_PER_SEC);
	#endif

    return 0;
}