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

int vis[29];
vector <int> graph[29];

void dfs(int cur)
{
    vis[cur] = 1;
    for(int i=0; i<graph[cur].size(); i++)
    {
        int v = graph[cur][i];
        if(!vis[v]) dfs(v);
    }
}
string str;
int main()
{//WRITE("out.txt");
    int tc;

    sf(tc);

    char maxi,u,v,c;

    while(tc--)
    {
        scanf(" %c", &maxi);//out(tc);

        int till = (maxi - 'A') + 1;
        //out(maxi);
        getchar();

        for(int i=0; i<29; i++) graph[i].clear();
        mem(vis,0);

        string str;
        str[0] = 'a';
        while(getline(cin,str) && str[0])
        {
            int a = (str[0] - 'A') + 1;
            int b = (str[1] - 'A') + 1;

            graph[a].pb(b);
            graph[b].pb(a);
        }//out("ok");


        int cnt = 0;
        for(int i=1; i<=till; i++)
        {
            if(!vis[i]) cnt++,dfs(i);
        }
        pf("%d\n", cnt);
        if(tc) pf("\n");
        //getchar();
    }

    return 0;

}